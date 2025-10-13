#include "hal/Motor.h"
#include <Arduino.h>

#include "config/pinout.h"

namespace Hal {
    Motor::Motor() {
        pinMode(Pinout::pins.motorPin, OUTPUT);
    }

    void Motor::moveForward(float distance) {
        digitalWrite(Pinout::pins.motorPin, HIGH);
    }
}

