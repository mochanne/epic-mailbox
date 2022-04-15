#include "DistanceSensor.h"

// Dit is een kort script dat laat zien hoe je de custom DistanceSensor klasse gebruikt

//DistanceSensor sensoren[] = {DistanceSensor(4,5)/};

DistanceSensor sensoren[] = {DistanceSensor(4,5), DistanceSensor(6,7), DistanceSensor(8,9), DistanceSensor(10,11), DistanceSensor(2,3)};

const int sensor_count = 5;
// DistanceSensor sensor(5,4);

void calibrate_all(DistanceSensor sns[]) {
    for (int i = 0; i < sensor_count; i++) {
        Serial.println("Calibrating #"+i);
        sns[i].calibrate();       
    }
}

void setup() {
    Serial.begin(9600);
    calibrate_all(sensoren);
}


int get_obstructed_count(DistanceSensor sns[]) {
    int obstructed_count = 0;
    for (int i = 0; i < sensor_count; i++) {
            Serial.print("getting obstruction on #");
            Serial.println(i);
        if (sns[i].is_obstructed()) {
            Serial.println("obstructed!");
            obstructed_count++;
        }
    }
    return obstructed_count;
}


void loop() {
//    DistanceSensor sensor = sensoren[0];
    int gaming = get_obstructed_count(sensoren);

    Serial.println(gaming);
    Serial.println();
    delay(500);
    

//    Serial.print("covered: ");
//    Serial.print(sensor.is_covered());
//    Serial.println();

//    Serial.print("Pulse/: ");
//    Serial.print(sensor.pu/lse());
//    Serial.println("μs");/


//    Serial.print("Distance: /");
//    Serial.print(sensor.get_dis/tance());
//    Serial.println("cm");/


//    long stable_pulse = sens/or.stable_pulse();
//    Serial.print("Stable pulse: ");
//    Serial.print( stable_pulse );
//    Serial.println("μs");
    
    
//    Serial.print("Stable distance: ");
//    Serial.print(  sensor.pulse_to_distance( stable_pulse )  );
//    Serial.println("cm");




//    Serial.print("obstruction: ");
//    Serial.print(sensor.get_obstruction());
//    Serial.println();
    
    
    
    
//    Serial.println();
//    delay(2000);
    
}
