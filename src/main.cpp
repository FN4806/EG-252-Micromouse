#include"config/pinout.h" // Pinout::pins
#include "hal/Motor.h" 
#include <Arduino.h>

//using hal::motor;
hal::Motor left_motor(config::pins.kMotor1PWM, config::pins.kMotor1Dir);
hal::Motor right_motor(config::pins.kMotor2PWM, config::pins.kMotor2Dir);

void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.println("Loop run");
}