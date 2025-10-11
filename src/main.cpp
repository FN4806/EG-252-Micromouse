#include "led_control.h"
#include"config/pinout.h"
#include <Arduino.h>

Led_Control led{LED_BUILTIN};
Pinout pins{};

void setup() {
  Serial.begin(9600);
  led.setSpeed(500);
}

void loop() {
  led.blinkLED();
  Serial.println("Loop run");
}