#ifndef PINOUT_H
#define PINOUT_H

namespace config {

    /// @brief Pre-defined pinouts for the microcontroller
    struct Pins {
        /// @brief Left motor pin, driven in forwards direction
        const int kLeftMotor1 = 6;

        /// @brief Left motor pin, driven in reverse direction
        const int kLeftMotor2 = 7;

        /// @brief Right motor pin 1, driven in forwards direction
        const int kRightMotor1 = 9;

        /// @brief Right motor pin 2, driven in reverse direction
        const int kRightMotor2 = 8;
    };

    extern Pins pins;
}

#endif