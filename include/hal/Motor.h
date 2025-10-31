#ifndef MOTOR_H
#define MOTOR_H

namespace hal {
    class Motor {
        public:
            Motor(int direction_pin, int driving_pin);
            void SetDirection(int direction);
            void SetSpeed(int speed);

        private:
            int direction_pin;
            int drive_pin;
            bool driving_direction{0};
            float current_speed{0};
    };
}

#endif