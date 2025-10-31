#ifndef PINOUT_H
#define PINOUT_H

namespace config {
    struct Pins {
        const int kExamplePin = 25;
        const int kNextExample = 14;

        // Pins for motor driving
        const int kLeftMotorPWM = 6;
        const int kLeftMotorDir = 7;
        const int kRightMotorPWM = 9;
        const int kRightMotorDir = 8;
    };

    extern Pins pins;
}

#endif