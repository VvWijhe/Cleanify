//
// Created by raymon on 2-5-17.
//

#ifndef CLEANIFY_ROOMBA_ALGORITHM_H
#define CLEANIFY_ROOMBA_ALGORITHM_H

#include "roomba_control.h"

namespace algorithm {
    class roomba_algorithm {
    public:
        using parameters = systemcontrol::RoombaControl::parameters;

        roomba_algorithm();

        ~roomba_algorithm() = default;

        virtual parameters calculate(parameters p, double dt) = 0;
    };

    class Clean : public roomba_algorithm {
    public:
        using parameters = systemcontrol::RoombaControl::parameters;
        typedef enum {
            S_NO, S_START, S_SPIRAL, S_FOLLOW_WALL, S_DRIVE_BACKWARDS, S_ROTATE_LEFT, S_BIG_ROTATE_LEFT, S_DRIVE_STRAIGT
        } state_e;
        typedef enum {
            E_NO, E_READY, E_HIT_OBJECT, E_TIME_EXCEEDED
        } event_e;

        Clean() : currentState(S_START), eventOut(E_NO) {}

        ~Clean() = default;

        parameters calculate(parameters p, double dt);

        state_e getCurrentState() const { return currentState; }

    private:
        state_e currentState;
        event_e eventOut;
    };

    class Spot : public roomba_algorithm {
    public:
        using parameters = systemcontrol::RoombaControl::parameters;
        typedef enum {
        } state_e;
        typedef enum {
        } event_e;

        parameters calculate(parameters p, double dt);


    };
}
#endif //CLEANIFY_ROOMBA_ALGORITHM_H
