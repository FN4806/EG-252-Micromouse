#include "hal/Motor_Encoder.h"

namespace hal {
    
    MotorEncoder::MotorEncoder(int pin1, int pin2) {
        MotorEncoder::pin_1 = pin1;
        MotorEncoder::pin_2 = pin2;
    }

    float MotorEncoder::ReadSpeed() {

    }
}