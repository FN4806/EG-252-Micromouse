#include "led_control.h"
#include <Arduino.h>

Led_Control::Led_Control(int pin) {
    ledPin = pin;
    pinMode(ledPin, OUTPUT); 
}

void Led_Control::setSpeed(int speed) {
    delaySpeed = speed;
}

void Led_Control::blinkLED() {
    digitalWrite(ledPin, HIGH);
    delay(delaySpeed);
    digitalWrite(ledPin, LOW);
    delay(delaySpeed);
}