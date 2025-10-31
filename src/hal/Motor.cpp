#include "hal/Motor.h"
#include <Arduino.h>

// Motor chip is a DRV8835
#include "config/pinout.h"

namespace hal {
    // Initialise a motor instance, must specify the driving and direction pins for the motor.
    Motor::Motor(int driving_pin, int direction_pin) {
        // Set the motor instance's pins
        Motor::drive_pin = driving_pin;
        Motor::direction_pin = direction_pin;

        // Ensure the correct pinouts and default pin values are set.
        pinMode(driving_pin, OUTPUT); digitalWrite(drive_pin, 1);
        pinMode(direction_pin, OUTPUT); digitalWrite(direction_pin, 1);
    }

    // Set the direction of the motor, direction int must be 0 or 1, for forward and reverse respectively.
    void Motor::SetDirection(int direction) {
        // If the specified direction is 1, set the direction else, set it to 0
        // This way handles any other integer being specified as it will just default to 0 direction 
        if (direction == 1) {
            driving_direction = 1;
        } else {
            driving_direction = direction;
        }

        SetSpeed(current_speed);
    }

    // Set the speed of the motor, max speed is 400, using a negative speed will reverse the direction.
    void Motor::SetSpeed(int speed) {
        if (speed > 400) {
            // If the speed is greater than 400, just cap it to max speed
            current_speed = 400;
        } else if (speed < 0) {
            // Since the speed is a negative number, reverse the direction of the motor
            SetDirection(!driving_direction);

            // Recursively call the SetSpeed function with a now positive speed value 
            // This will ensure that the max speed is still enforced
            SetSpeed(-speed);
        } else {
            // If it gets to this point, the speed is between 0-400 and can be set directly
            current_speed = speed;
        }

        // Calculate the speed value with 255 as the max PWM value
        int PWM_speed = (current_speed/400)*255;

        // If the direction is reversed, then the motor is actuated on the lows of the PWM
        // signal, so for max speed to still be the largest value, it needs to be flipped
        if (driving_direction == 1) {
            analogWrite(Motor::drive_pin, 0);
            analogWrite(Motor::direction_pin, PWM_speed);
        } else {
            analogWrite(Motor::direction_pin, 0);
            analogWrite(Motor::drive_pin, PWM_speed);
        }
    }
}