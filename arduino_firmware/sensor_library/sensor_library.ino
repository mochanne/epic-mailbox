#include "DistanceSensor.h"

// Dit is een kort script dat laat zien hoe je de custom DistanceSensor klasse gebruikt


DistanceSensor sensoren[] = {DistanceSensor(4,5)};
// DistanceSensor sensor(5,4);

void calibrate_all(DistanceSensor sns[]) {
    for (int i = 0; i < sizeof(sns)/sizeof(sns[0]); i++) {
        sns[i].calibrate();
    }
}

void setup() {
    Serial.begin(9600);
    calibrate_all(sensoren);
}


bool get_obstructed_count(DistanceSensor sns[]) {
    int obstructed_count = 0;
    for (int i = 0; i < sizeof(sns)/sizeof(sns[0]); i++) {
        if (sns[i].is_obstructed()) {
            obstructed_count++;
        }
    }
    return obstructed_count;
}


void loop() {
    DistanceSensor sensor = sensoren[0];
    get_obstructed_count(sensoren);

    Serial.print("covered: ");
    Serial.print(sensor.is_covered());
    Serial.println();

    Serial.print("Pulse: ");
    Serial.print(sensor.pulse());
    Serial.println("μs");


    Serial.print("Distance: ");
    Serial.print(sensor.get_distance());
    Serial.println("cm");


    long stable_pulse = sensor.stable_pulse();
    Serial.print("Stable pulse: ");
    Serial.print( stable_pulse );
    Serial.println("μs");
    
    
    Serial.print("Stable distance: ");
    Serial.print(  sensor.pulse_to_distance( stable_pulse )  );
    Serial.println("cm");




    Serial.print("obstruction: ");
    Serial.print(sensor.get_obstruction());
    Serial.println();
    
    
    
    
    Serial.println();
    delay(2000);
    
}
