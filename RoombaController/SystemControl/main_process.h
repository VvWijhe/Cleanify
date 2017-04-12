//
// Created by jamie on 3/28/17.
//

#include <memory>

#include "../Server/server.h"
#include "roomba_control.h"
#include "statemachine.hpp"

#ifndef ROOMBACONTROLLER_PROCESSING_H
#define ROOMBACONTROLLER_PROCESSING_H

namespace systemControl {
    /**
     * @brief RoombaContext contains variables and classes that can be accessed by every state.
     */
    class RoombaContext : public statemachine::Context {
    public:
        /**
         * @brief Constructor allocates the server and roomba control.
         */
        RoombaContext() {
            server_ = std::make_shared<server::RoombaServer>(8000);
            control_ = std::make_shared<RoombaControl>("/dev/ttyUSB0", RoombaControl::b115200);
        }

        /**
         * @return A shared pointer that owns the server object.
         */
        std::shared_ptr<server::RoombaServer>  getServer() const { return server_; }

        /**
         * @return A shared pointer that owns the roomba control object
         */
        std::shared_ptr<RoombaControl> getControl() const { return control_; }

    private:
        std::shared_ptr<server::RoombaServer> server_;
        std::shared_ptr<RoombaControl> control_;
    };

    /**
     * @brief State class that waits for a signal of a PC or website
     */
    class WaitForCmd : public statemachine::State {
    public:
        ~WaitForCmd() {}

        void handle(std::shared_ptr<statemachine::Context> context, statemachine::event_t event) override;
    };

    /**
     * @brief State class that handles the cleaning.
     */
    class Clean : public statemachine::State {
    public:
        ~Clean() {}

        void handle(std::shared_ptr<statemachine::Context> context, statemachine::event_t event) override;
    };
}

#endif //ROOMBACONTROLLER_PROCESSING_H
