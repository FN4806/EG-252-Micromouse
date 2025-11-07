#ifndef MOTOR_H
#define MOTOR_H

namespace hal {
    class Motor {
        public:
            Motor(int direction_pin, int driving_pin);
            void SetDirection(int direction);
            void SetSpeed(int speed);
            void Brake(void);
            void Freewheel(void);
            void StartMotorPWM();

        private:
            int direction_pin;
            int drive_pin;
            bool driving_direction{0};
            int current_speed{0};
    };
}

#endif