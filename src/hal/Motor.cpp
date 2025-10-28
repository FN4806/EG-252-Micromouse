#include "hal/Motor.h"
#include <Arduino.h>
#include <DRV8835MotorShield.h>

// Motor chip is a DRV8835

#include "config/pinout.h"

using config::pins;
DRV8835MotorShield motor_driver;

namespace hal {
    Motor::Motor() {
        motor_driver = DRV8835MotorShield(
            config::pins.kMotor1Dir,
            config::pins.kMotor1PWM, 
            config::pins.kMotor2Dir, 
            config::pins.kMotor2PWM
        );
    }

    void Motor::MoveForward(float distance) {
        
    }

    void Motor::SetRawSpeed(int speed) {
        motor_driver.setM1Speed(speed);
        motor_driver.setM2Speed(speed);
    }

    void Motor::SpinLeft() {
        motor_driver.flipM1(true);
        motor_driver.flipM2(false);
        motor_driver.setM1Speed(100);
        motor_driver.setM2Speed(100);
    }
}

