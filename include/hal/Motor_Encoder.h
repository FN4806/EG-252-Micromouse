#ifndef MOTOR_ENCODER_H
#define MOTOR_ENCODER_H

namespace hal {
    class MotorEncoder {
        public:
            MotorEncoder(int pin1, int pin2); // Constructor
            float ReadSpeed();

        private:
            int pin_1{0};
            int pin_2{0};
    };
}

#endif