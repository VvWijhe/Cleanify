//
// Created by raymon on 2-5-17.
//

#ifndef CLEANIFY_ROOMBA_ALGORITHM_H
#define CLEANIFY_ROOMBA_ALGORITHM_H

#include "roomba_control.h"
#include <string>

namespace algorithm {
    const int full_speed = 300;

    class Timer {
    public:
        using clock = std::chrono::high_resolution_clock;
        using second = std::chrono::duration<double, std::ratio<1>>;

        Timer() : beg_(clock::now()) {}

        void reset() { beg_ = clock::now(); }

        double elapsed() {
            auto tmp = std::chrono::duration_cast<second>
                    (clock::now() - beg_).count();
            reset();
            return tmp;
        }

    private:
        std::chrono::time_point<clock> beg_;
    };

    class roomba_algorithm {
    public:
        roomba_algorithm() {}

        virtual ~roomba_algorithm() = default;

        virtual void
        calculate(shared_ptr<systemcontrol::RoombaControl> control, Sensors sensorData, double dt) = 0;
    };

    class Clean : public roomba_algorithm {
    public:
        typedef enum {
            S_START, S_SPIRAL, S_FOLLOW_WALL, S_DRIVE_BACKWARDS, S_ROTATE_LEFT, S_BIG_ROTATE_LEFT, S_DRIVE_STRAIGT
        } state_e;

        Clean() : currentState_(S_START) {}

        ~Clean() = default;

        void
        calculate(shared_ptr<systemcontrol::RoombaControl> control, Sensors sensorData, double dt) override;

        state_e getCurrentState() const { return currentState_; }

    private:
        state_e currentState_;
        double dt_;
    };

    class Spot : public roomba_algorithm {
    public:
        void calculate(shared_ptr<systemcontrol::RoombaControl> control, Sensors sensorData, double dt) override;
    };

    class Dock : public roomba_algorithm {
    public:
        void calculate(shared_ptr<systemcontrol::RoombaControl> control, Sensors sensorData, double dt) override;
    };
}
#endif //CLEANIFY_ROOMBA_ALGORITHM_H
