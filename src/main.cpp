#include"config/pinout.h" // Pinout::pins
#include "hal/Motor.h" 
#include <Arduino.h>

using hal::motor;

void setup() {
  Serial.begin(9600);

  motor.MoveForward(25);
}

void loop() {
  Serial.println("Loop run");
}