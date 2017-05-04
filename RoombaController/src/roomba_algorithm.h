//
// Created by raymon on 2-5-17.
//

#ifndef CLEANIFY_ROOMBA_ALGORITHM_H
#define CLEANIFY_ROOMBA_ALGORITHM_H

#include "roomba_control.h"
#include <string>

namespace algorithm {
    const int full_speed = 300;

    class roomba_algorithm {
    public:
        using parameters = systemcontrol::RoombaControl::parameters;

        roomba_algorithm() {}

        virtual ~roomba_algorithm() = default;

        virtual void
        calculate(shared_ptr<systemcontrol::RoombaControl> control, Sensors sensorData, double dt) = 0;
    };

    class Clean : public roomba_algorithm {
    public:
        using parameters = systemcontrol::RoombaControl::parameters;
        typedef enum {
            S_NO, S_START, S_SPIRAL, S_FOLLOW_WALL, S_DRIVE_BACKWARDS, S_ROTATE_LEFT, S_BIG_ROTATE_LEFT, S_DRIVE_STRAIGT
        } state_e;
        typedef enum {
            E_NO,
            E_READY,
            E_HIT_OBJECT,
            E_TIME_EXCEEDED,
            E_ROTATE_DONE,
            E_BACKWARDS_DONE,
        } event_e;

        Clean() : currentState_(S_START), eventOut_(E_NO) {}

        ~Clean() = default;

        void
        calculate(shared_ptr<systemcontrol::RoombaControl> control, Sensors sensorData, double dt) override;

        state_e getCurrentState() const { return currentState_; }

    private:
        state_e currentState_;
        event_e eventOut_;
    };

    class Spot : public roomba_algorithm {
    public:
        using parameters = systemcontrol::RoombaControl::parameters;

        typedef enum {
        } state_e;
        typedef enum {
        } event_e;

        void calculate(shared_ptr<systemcontrol::RoombaControl> control, Sensors sensorData, double dt) override;
    };
}
#endif //CLEANIFY_ROOMBA_ALGORITHM_H
