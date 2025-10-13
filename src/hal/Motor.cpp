#include "hal/Motor.h"
#include <Arduino.h>

#include "config/pinout.h"

using Pinout::pins;

namespace Hal {
    Motor::Motor() {
        pinMode(pins.motorPin, OUTPUT);
    }

    void Motor::moveForward(float distance) {
        digitalWrite(pins.motorPin, HIGH);
    }
}

