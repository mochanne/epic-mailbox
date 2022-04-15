/*

    Class voor een ultrasonische afstandssensor
    
    Anne

*/


#ifndef DistanceSensor_h

#define DistanceSensor_h
#include "Arduino.h"

class DistanceSensor
{
    public:
        DistanceSensor(int trig_pin, int echo_pin);
        bool is_covered(long covered_pulse = 18000);
        long pulse();
        double get_distance();
        double pulse_to_distance(long pulse);
        long stable_pulse(int repeats = 5);

        void calibrate(int repeats = 10, double margin = 0.97);
        double get_obstruction();
        bool is_obstructed(double obstructed_percentage = 0.50);

        double baseline = 0;
    private:
        int _trig_pin;
        int _echo_pin;
};

#endif
