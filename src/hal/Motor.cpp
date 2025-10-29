#include "hal/Motor.h"
#include <Arduino.h>

// Motor chip is a DRV8835

#include "config/pinout.h"

using config::pins;

namespace hal {
    Motor::Motor(int driving_pin, int direction_pin) {
        Motor::drive_pin = driving_pin;
        Motor::direction_pin = direction_pin;

        pinMode(driving_pin, OUTPUT); digitalWrite(drive_pin, LOW);
        pinMode(direction_pin, OUTPUT); digitalWrite(direction_pin, LOW);
    }

    void Motor::SetDirection(int direction) {
        if ((driving_direction > 1) or (driving_direction < 0)) {
            driving_direction = 0;
        } else {
            driving_direction = direction;
        }
    }

    void Motor::SetSpeed(int speed) {
        if ((speed <= 400) and (speed >= 0)) {
            current_speed = speed;
        } else if (speed > 400) {
            speed = 400;
        } else if (speed < 0) {
            SetDirection(!driving_direction);
            current_speed = -speed;
        }
    }
}

