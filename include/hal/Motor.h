#ifndef MOTOR_H
#define MOTOR_H

namespace hal {
    class Motor {
        public:
            Motor();
            void MoveForward(float distance);
            void SetRawSpeed(int speed);
            void SpinLeft();
    };

    extern Motor motor;
}

#endif