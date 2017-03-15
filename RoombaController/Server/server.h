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

namespace server {
    using httpServer = SimpleWeb::Server<SimpleWeb::HTTP>;

    const std::string response200("HTTP/1.1 200 OK\r\n");
    const std::string response404("HTTP/1.1 404 Bad Request\r\n");

    class RoombaServer {
    public:
        RoombaServer(unsigned short port);

        ~RoombaServer();

        void run();

        void htmlResponse(const httpServer &server, const std::shared_ptr<httpServer::Response> &response,
                          const std::shared_ptr<std::ifstream> &ifs);

    private:
        httpServer server_;
        std::thread thread_;
    };

}

#endif //ROOMBACONTROLLER_SERVER_H
