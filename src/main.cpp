#include"config/pinout.h" // Pinout::pins
#include "hal/Motor.h" 
#include <Arduino.h>

//using hal::motor;
hal::Motor left_motor(config::pins.kLeftMotorPWM, config::pins.kLeftMotorDir);
hal::Motor right_motor(config::pins.kRightMotorPWM, config::pins.kRightMotorDir);

void setup() {
  Serial.begin(9600);
}

void loop() {
  left_motor.SetSpeed(200);
  right_motor.SetSpeed(200);

  left_motor.SetDirection(1);
  right_motor.SetDirection(1);

  delay(1000);

  left_motor.SetDirection(0);
  right_motor.SetDirection(0);

  delay(1000);
}