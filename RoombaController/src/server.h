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
    /**
     * @brief Class that sets up a HTTP server.
     */
    class RoombaServer {
    public:
        /**
         * @brief Constructor sets the port and makes recources available for the client.
         * @param port
         */
        RoombaServer(unsigned short port);

        /**
         * @brief Destructor stops the server.
         */
        ~RoombaServer();

        /**
         * @brief Starts the server.
         */
        void run();

        /**
         * @brief Stops the server.
         */
        void stop();

        /**
         * @brief Checks is the server is started.
         * @return
         */
        bool started() const;

    private:
        restbed::Service service_;
        std::shared_ptr<restbed::Settings> settings_;
        std::thread thread_;
        bool isStarted;
    };
}

#endif //ROOMBACONTROLLER_SERVER_H
