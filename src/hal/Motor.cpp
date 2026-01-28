#include "hal/Motor.h"
#include <Arduino.h>

// Motor chip is a DRV8835
#include "config/pinout.h"

/*
The DRV8835 IC is set to the IN/IN configuration mode, in this mode
it has the following operating modes (taken from polulu):
   ________________________________________________________________
  |  IN1  |  IN2  | OUT1      | OUT2      | MODE                  |
  |-------|-------|-----------|-----------|-----------------------|
  |   0   |   0   |     Z     |     Z     | COAST (OUTPUT OFF)    |
  |  PWM  |   0   | PWM(H/Z)  | PWM(L/Z)  | FORWARD/COAST PWM     |
  |   0   |  PWM  | PWM(L/Z)  | PWM(H/Z)  | REVERSE/COAST PWM     |
  |  PWM  |   1   |     L     | PWM(L/Z)  | REVERSE/BRAKE PWM     |
  |   1   |  PWM  | PWM(L/Z)  |     L     | FORWARD/BRAKE PWM     |
  |   1   |   1   |     L     |     L     | BRAKE - OUTPUTS TO GND|
  |_______|_______|___________|___________|_______________________|
*/


namespace hal {

    static constexpr int max_speed = 4095;
    static constexpr int max_pwm_val = 4095;

    /// @brief Initialise a motor instance
    /// @param motor_pin_1 One of the motor pins, driven in clockwise direction
    /// @param motor_pin_2 Other motor pin, driven in anticlockwise direction
    Motor::Motor(int motor_pin_1, int motor_pin_2) {
        // Set the motor instance's pins
        Motor::pin_1 = motor_pin_1;
        Motor::pin_2 = motor_pin_2;

        // Ensure the correct pinouts and default pin values are set.
        pinMode(pin_1, OUTPUT); digitalWrite(pin_1, 0);
        pinMode(pin_2, OUTPUT); digitalWrite(pin_2, 0);
    }

    /// @brief Set the direction of the motor
    /// @param direction Set using the DrivingDirection enum, with anticlockwise or clockwise
    void Motor::SetDirection(DrivingDirection direction) {
        Serial.println("Setting Direction");
        
        Serial.print("motor on pins: ");
        Serial.print(pin_1);
        Serial.print(" and ");
        Serial.println(pin_2);

        driving_direction = direction;

        StartMotorPWM();
    }

    /// @brief Set the speed of the motor, setting the speed to 0 will put the wheels into freewheel, to stop a motor, the brake function is reccomended, see Motor::Brake()
    /// @param speed Desired speed of the motor, an integer between 0-4096, a negative value will reverse the motor and set to the absolute speed value.
    void Motor::SetSpeed(int speed) {
        Serial.println("Setting Speed");
        if (speed > max_speed) {
            // If the speed is greater than 4096, just cap it to max speed
            current_speed = max_pwm_val;
        } else if (speed < 0) {

            // Set the current speed to the absolute value of the speed given (provided it's within the max range)
            if (speed < -max_speed) current_speed = max_pwm_val; else current_speed = ((-speed)*max_pwm_val)/max_speed;

            // Since the speed is a negative number, reverse the direction of the motor
            if (driving_direction == DrivingDirection::kClockwise) {
                driving_direction = DrivingDirection::kAnticlockwise;
            } else {
                driving_direction = DrivingDirection::kClockwise;
            }

        } else {
            // If it gets to this point, the speed is between 0-4096 and can be calculated directly from the max PWM value
            current_speed = (speed*max_pwm_val)/max_speed;
        }

        // If the direction is reversed, then the motor is actuated on the lows of the PWM
        // signal, so for max speed to still be the largest value, it needs to be flipped
        StartMotorPWM();
    }

    /// @brief Sets the motor into brake mode
    void Motor::Brake(void) {
        analogWrite(pin_1, 0);
        digitalWrite(pin_1, 1);

        analogWrite(pin_2, 0);
        digitalWrite(pin_2, 1);
    }

    /// @brief Disengages motor control, letting the wheels turn freely
    void Motor::Freewheel(void) {
        analogWrite(pin_1, 0);
        digitalWrite(pin_1, 0);
        
        analogWrite(pin_2, 0);
        digitalWrite(pin_2, 0);
    }

    /// @brief Start or change the PWM signal going to the motors
    void Motor::StartMotorPWM(void) {
        Serial.println("Trying to start PWM");
        if (driving_direction == DrivingDirection::kAnticlockwise) {
            Serial.println("Attempting to drive in ACW direction");
            analogWrite(pin_1, 0);
            digitalWrite(pin_1, 0);
            analogWrite(pin_2, current_speed);
        } else {
            Serial.println("Attempting to drive in CW direction");
            analogWrite(pin_1, current_speed);
            analogWrite(pin_2, 0);
            digitalWrite(pin_2, 0);
        }
    }
}