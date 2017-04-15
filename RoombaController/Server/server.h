//
// Created by jamie on 3/15/17.
//

#ifndef ROOMBACONTROLLER_SERVER_H
#define ROOMBACONTROLLER_SERVER_H

#include <thread>
#include <fstream>
#include <memory>
#include <vector>
#include <algorithm>

#include <restbed>
#include "responses.h"

namespace server {
    class RoombaServer {
    public:
        RoombaServer(unsigned short port);

        ~RoombaServer();

        void run();

        void stop();

    private:
        restbed::Service service_;
        std::shared_ptr<restbed::Settings> settings_;
        std::thread thread_;
        bool isStarted{false};
    };
}

#endif //ROOMBACONTROLLER_SERVER_H
