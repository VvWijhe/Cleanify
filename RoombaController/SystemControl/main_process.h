//
// Created by jamie on 3/28/17.
//

#include "../Server/server.h"
#include "roomba_control.h"
#include "statemachine.hpp"

#ifndef ROOMBACONTROLLER_PROCESSING_H
#define ROOMBACONTROLLER_PROCESSING_H

namespace systemControl {
    class RoombaProcessing : public Statemachine {
    public:
        enum states {init_s, test_s};
        enum events {timeout_e};

        RoombaProcessing();

        static void init(State *currentState);

        static void test(State *currentState);

    private:
        static server::RoombaServer server_;
        static RoombaControl control_;
    };
}

#endif //ROOMBACONTROLLER_PROCESSING_H
