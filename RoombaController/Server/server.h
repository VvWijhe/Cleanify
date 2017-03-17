//
// Created by jamie on 3/15/17.
//

#ifndef ROOMBACONTROLLER_SERVER_H
#define ROOMBACONTROLLER_SERVER_H

#include <thread>
#include <fstream>
#include <boost/filesystem.hpp>
#include <vector>
#include <algorithm>

#include "http_server.hpp"
#include "responses.h"

namespace server {
    using httpServer = SimpleWeb::Server<SimpleWeb::HTTP>;

    class RoombaServer {
    public:
        RoombaServer(unsigned short port);

        ~RoombaServer();

        void run();

        void stop();

        void htmlResponse(const httpServer &server, const std::shared_ptr<httpServer::Response> &response,
                          const std::shared_ptr<std::ifstream> &ifs);

    private:
        httpServer server_;
        std::thread thread_;
    };
}

#endif //ROOMBACONTROLLER_SERVER_H
