#include "hal/Motor.h"
#include <Arduino.h>

#include "config/pinout.h"

using config::pins;

namespace Hal {
    Motor::Motor() {
        pinMode(pins.kMotorPin, OUTPUT);
    }

    void Motor::moveForward(float distance) {
        digitalWrite(pins.kMotorPin, HIGH);
    }
}

