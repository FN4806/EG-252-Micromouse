#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

namespace motor_controller {
    bool MoveDistance(float distance_m);
    bool Rotate(float angle_deg);
}

#endif