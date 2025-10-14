#ifndef MOTOR_H
#define MOTOR_H

namespace hal {
    class Motor {
        public:
            Motor();
            void MoveForward(float distance);
    };

    extern Motor motor;
}

#endif