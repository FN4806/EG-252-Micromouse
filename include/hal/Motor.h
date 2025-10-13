#ifndef MOTOR_H
#define MOTOR_H

namespace Hal {
    class Motor {
        Motor();
        void moveForward(float distance);
    };

    extern Motor motor;
}

class Motor {
    Motor();
    void moveForward(float distance);
};

#endif