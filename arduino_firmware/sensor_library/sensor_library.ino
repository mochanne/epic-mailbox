#include "DistanceSensor.h"

// Dit is een kort script dat laat zien hoe je de custom DistanceSensor klasse gebruikt




DistanceSensor sensor(5,4);

void setup() {
    Serial.begin(9600);
    sensor.calibrate();
}


void loop() {
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
