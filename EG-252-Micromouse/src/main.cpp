#include"config/pinout.h" // Pinout::pins
#include "hal/Motor.h" 
#include <Arduino.h>

void setup() {
  Serial.begin(9600);

  Hal::motor.moveForward(25);
}

void loop() {
  Serial.println("Loop run");
}