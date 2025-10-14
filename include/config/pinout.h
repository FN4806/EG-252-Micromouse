#ifndef PINOUT_H
#define PINOUT_H

namespace config {
    struct Pins {
        const int kExamplePin = 25;
        const int kNextExample = 14;
        const int kMotorPin = 3;
    };

    extern Pins pins;
}

#endif