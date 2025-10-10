#include "led_control.h"
#include <Arduino.h>

Led_Control led(25);

void setup() {
  Serial.begin(9600);
  led.setSpeed(500);
}

void loop() {
  led.blinkLED();
  Serial.println("Loop run");
}