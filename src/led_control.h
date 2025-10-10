#ifndef LED_CONTROL_H
#define LED_CONTROL_H

class Led_Control{
    public:
        Led_Control(int pin);
        void setSpeed(int speed);
        void blinkLED();

    private:
        int ledPin;
        int delaySpeed;
};

#endif