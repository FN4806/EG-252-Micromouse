#include "hal/Motor.h"
#include <Arduino.h>

#include "config/pinout.h"

using config::pins;

namespace hal {
    Motor::Motor() {
        pinMode(pins.kMotorPin, OUTPUT);
    }

    void Motor::MoveForward(float distance) {
        digitalWrite(pins.kMotorPin, HIGH);
    }
}

