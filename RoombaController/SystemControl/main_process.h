//
// Created by jamie on 3/28/17.
//

#include "../Server/server.h"
#include "roomba_control.h"

#ifndef ROOMBACONTROLLER_PROCESSING_H
#define ROOMBACONTROLLER_PROCESSING_H

namespace systemControl {
    class mainProcessing{
    public:
        mainProcessing() : server_(80) { }
        void serverHandler

    private:
        server::RoombaServer server_;
        RoombaControl roombacontrol_;

    };
}

#endif //ROOMBACONTROLLER_PROCESSING_H
