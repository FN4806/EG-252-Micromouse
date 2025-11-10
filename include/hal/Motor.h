#ifndef MOTOR_H
#define MOTOR_H

namespace hal {
    /// @brief Enum used to set the driving direction of motors
    enum class DrivingDirection {
        kClockwise,
        kAnticlockwise
    };
    
    class Motor {
        public:
            Motor(int driving_pin, int direction_pin);
            void SetDirection(DrivingDirection direction);
            void SetSpeed(int speed);
            void Brake(void);
            void Freewheel(void);
            void StartMotorPWM(void);

        private:
            int pin_1{0};
            int pin_2{0};
            DrivingDirection driving_direction{DrivingDirection::kClockwise};
            float current_speed{0};
    };
}

#endif