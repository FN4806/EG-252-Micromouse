#include <Arduino.h>
#include"config/pinout.h" // Pinout::pins
#include "hal/Motor.h" 

//using hal::motor;
hal::Motor left_motor(config::pins.kLeftMotor1, config::pins.kLeftMotor2);
hal::Motor right_motor(config::pins.kRightMotor1, config::pins.kRightMotor2);

void SelectMode() {
  
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Hello!");
  left_motor.SetSpeed(200);
  right_motor.SetSpeed(200);

  left_motor.SetDirection(hal::DrivingDirection::kAnticlockwise);
  right_motor.SetDirection(hal::DrivingDirection::kAnticlockwise);

  delay(1000);

  left_motor.SetDirection(hal::DrivingDirection::kClockwise);
  right_motor.SetDirection(hal::DrivingDirection::kClockwise);

  delay(1000);
}