#include"config/pinout.h" // Pinout::pins
#include "hal/Motor.h" 
#include <Arduino.h>

//using hal::motor;
hal::Motor motor;

void setup() {
  Serial.begin(9600);

  motor.SpinLeft();
}

void loop() {
  Serial.println("Loop run");
}