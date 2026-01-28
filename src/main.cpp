#include <Arduino.h>
#include"config/pinout.h" // Pinout::pins
#include "hal/Motor.h" 
#include "hal/Motor_Encoder.h"

//using hal::motor;
hal::Motor left_motor(config::pins.kLeftMotor1, config::pins.kLeftMotor2);
hal::Motor right_motor(config::pins.kRightMotor1, config::pins.kRightMotor2);

hal::MotorEncoder left_encoder(1, 2);
hal::MotorEncoder right_encoder(3, 4);

void SelectMode() {
  
}

void setup() {
  Serial.begin(9600);
  analogWriteResolution(12);

  // Initialise startup pin modes
  pinMode(config::pins.kRightMotor1, OUTPUT);
  pinMode(config::pins.kRightMotor2, OUTPUT);
  pinMode(config::pins.kLeftMotor1, OUTPUT);
  pinMode(config::pins.kLeftMotor2, OUTPUT);
}

void loop() {
  Serial.println("Hello!");
  // left_motor.SetSpeed(2048);
  // right_motor.SetSpeed(2048);

  left_motor.SetDirection(hal::DrivingDirection::kAnticlockwise);
  right_motor.SetDirection(hal::DrivingDirection::kAnticlockwise);

  for (int speed = 0; speed < 4096; speed+=16) {
    left_motor.SetSpeed(speed);
    right_motor.SetSpeed(speed);
    delay(10);
  }

  left_motor.SetDirection(hal::DrivingDirection::kClockwise);
  right_motor.SetDirection(hal::DrivingDirection::kClockwise);

  for (int speed = 0; speed < 4096; speed+=16) {
    left_motor.SetSpeed(speed);
    right_motor.SetSpeed(speed);
    delay(10);
  }
}