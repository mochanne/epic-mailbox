const int trig_pin = 5;
const int echo_pin = 4;


void setup() {
    // put your setup code here, to run once:
    pinMode(trig_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
    digitalWrite(trig_pin, LOW);
    Serial.begin(9600);
}

float get_raw_pulse(int trig, int echo) {
    // Trigger de sensor om de transmitter aan te zetten
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    // Wacht totdat echo HIGH gaat, en meet de tijd
    // Dit geeft dus de tijd in ms dat het duurde totdat het ultrasonische geluid terug kwam
    long pulse_time = pulseIn(echo, HIGH);
    // !!! kan 0 zijn als het signaal nooit HIGH gaat
    // !!! dit getal word heel groot als de sensor bedekt is!! 
    // ongeveer tussen ~18000 tot ~20000 ms, oftewel ~3200cm
    // Het is veilig om aan te nemen dat alle waardes boven 18000 betekent dat het bedekt is
    return pulse_time;
}

long pulse_to_distance(long pulse_time) {
    // afstand in cm (afstand in cm per microseconde, gedeeld door 2 omdat het ultrasonische geluid heen en terug gaat)
    return pulse_time * 0.0343 / 2;
}


long get_distance(int trig, int echo) {
    // Ease of use functie
    return pulse_to_distance(  get_raw_pulse(trig_pin, echo_pin) );
}



void loop() {
    long afstand = get_distance(trig_pin, echo_pin);
    Serial.print(afstand);
    Serial.print("cm");
    Serial.println();
    delay(300);
}