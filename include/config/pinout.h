#ifndef PINOUT_H
#define PINOUT_H

namespace config {
    struct Pins {
        const int kExamplePin = 25;
        const int kNextExample = 14;

        // Pins for motor driving
        const int kMotor1PWM = 9;
        const int kMotor1Dir = 8;
        const int kMotor2PWM = 7;
        const int kMotor2Dir = 6;
    };

    extern Pins pins;
}

#endif