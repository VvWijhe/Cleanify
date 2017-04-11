//
// Created by jamie on 3/28/17.
//

#include "../Server/server.h"
#include "roomba_control.h"
#include "statemachine.hpp"

#ifndef ROOMBACONTROLLER_PROCESSING_H
#define ROOMBACONTROLLER_PROCESSING_H

namespace systemControl {
    /**
     * @brief The RoombaProcessing class contains the main program for the roomba. A statemachine handles the
     * states using member callback functions. Every state can set a nextstate and event using the State object that
     * is passed to a callback function. The default next state is 'nstate' which shuts down the statemachine
     */
    class RoombaProcessing : public Statemachine {
    public:
        /**
         * @brief Enumeration of states, which makes it easier to identify states by ID
         */
        enum states {init_s, waitForMode_s};

        /**
         * @brief Enumeration of events. Every state can exit with an event. The next state can receive this event.
         */
        enum events {ready_e, timeout_e};

        RoombaProcessing();

        /**
         * @brief State connects the serial port and starts the server.
         * @param currentState
         */
        static void init(State *currentState);

        /**
         * @brief State waits for a flag change that determines the mode.
         * @param currentState
         */
        static void waitForMode(State *currentState);

        /**
         * @brief State that lets the roomba clean a room.
         * @param currentState
         */
        static void clean(State *currentState);

        /**
         * @brief State that lets the roomba clean a small area.
         * @param currentState
         */
        static void spot(State *currentState);

    private:
        static server::RoombaServer server_;
        static RoombaControl control_;
    };
}

#endif //ROOMBACONTROLLER_PROCESSING_H
