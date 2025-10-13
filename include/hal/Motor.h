#ifndef MOTOR_H
#define MOTOR_H

namespace Hal {
    class Motor {
        public:
            Motor();
            void moveForward(float distance);
    };

    extern Motor motor;
}

#endif