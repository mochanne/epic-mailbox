#include "Arduino.h"
#include "DistanceSensor.h"


DistanceSensor::DistanceSensor(int trig_pin, int echo_pin) {
    pinMode(trig_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
    _echo_pin = echo_pin;
    _trig_pin = trig_pin;
}


long DistanceSensor::pulse() {
    // Trigger de sensor om de transmitter aan te zetten
    digitalWrite(_trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trig_pin, LOW);

    // Wacht totdat echo HIGH gaat, en meet de tijd
    // Dit geeft dus de tijd in μs dat het duurde totdat het ultrasonische geluid terug kwam
    long pulse_time = pulseIn(_echo_pin, HIGH);
    // !!! kan 0 zijn als het signaal nooit HIGH gaat
    // !!! dit getal word heel groot als de sensor bedekt is!! 
    // ongeveer tussen ~18000 tot ~20000 μs, oftewel ~3200cm
    // Het is veilig om aan te nemen dat alle waardes boven 18000 betekent dat het bedekt is
    return pulse_time;
}


long DistanceSensor::stable_pulse(int repeats = 5) {
    // Deze functie neemt de gemmidelde pulse over repeats*0.05 seconden
    // Handig om een stabielere afstand te krijgen
    // !!! niet aan te raden om elke loop uit te voeren, want het is veel langzaamer
    long out = 0;
    for (int i = 0; i < repeats; i++) {
        out = out + pulse();
        delay(50);
    }
    return out/repeats;
}


double DistanceSensor::pulse_to_distance(long pulse_time) {
    // afstand in cm (afstand in cm per microseconde, gedeeld door 2 omdat het ultrasonische geluid heen en terug gaat)
    return double(pulse_time) * 0.0343 / 2;
}


double DistanceSensor::get_distance() {
    // Ease of use functie
    // Doet automatisch een pulse en returned de afstand in cm
    return pulse_to_distance(  pulse() );
}


bool DistanceSensor::is_covered(long covered_pulse = 18000) {
    // Let op: dit geeft aan of de sensor *waarschijnlijk* bedekt is, en kan verkeerd zijn als de sensor over grote afstanden werkt
    // Als er wel met grote afstanden word gewerkt (ik gok ongeveer >5 meter), zal dit vaak valspositieven geven
    return pulse() > covered_pulse;
}





void DistanceSensor::calibrate(int repeats = 10, double margin = 0.97) {
    // Zet de baseline naar een stabiele afstand. Hierdoor is te meten hoever iets tussen de bovenkant van de brievenbuse en de sensor zit

    // dit __moet__ minstend 1x gedaan worden om de functies hieronder te gebruiken
    // aan te raden om in de setup() aan te roepen
    baseline = stable_pulse(repeats)*margin;
}

double DistanceSensor::get_obstruction() {
    // % Afstand dat iets zit tussen de bovenkant van de brievenbus en de sensor
    // Handig om te meten of er iets ligt als het niet de hele sensor blokkeerd
    // Dit is een goede manier om te meten of er post is, b.v. als het resultaat < 0.2 is ofzo
    
    // Returns een kommagetal tussen 0.0 en 1.0
    // 1.0: de brievenbus
    // 0.0: de sensor

    // dus 0.999 tot 0.0: er zit iets x % van de sensor vandaan
    // b.v. 0.23: er zit iets dicht bij de sensor
    // b.b. 0.76: er zit iets dicht bij het dak van de brievenbus

    // omdat de calibratie een error margin heeft, kan het zijn dat het resultaat > 1.0 is.
    // Dit word automatisch naar 1.0 omgezet.
    // Als `is_covered == true`, dan word 0.0 ge-returned
    
    long puls = pulse();

    if (puls > 18000) {return 0.0;}
    
    double out = puls/baseline;
    if (out > 1.0) { out = 1.0; }
    return out;
}


bool DistanceSensor::is_obstructed(double obstructed_percentage = 0.9) {
    return get_obstruction() < obstructed_percentage;
}


