//
// Created by jamie on 3/28/17.
//

#include <memory>

#include "server.h"
#include "roomba_control.h"
#include "statemachine.hpp"

#ifndef ROOMBACONTROLLER_PROCESSING_H
#define ROOMBACONTROLLER_PROCESSING_H

namespace systemcontrol {
    /**
     * @brief RoombaContext holds variables and classes that can be accessed by every state.
     */
    class RoombaStateContext : public statemachine::Context {
    public:
        /**
         * @brief Constructor allocates the server and roomba control.
         */
        RoombaStateContext(const std::shared_ptr<statemachine::State> &initial) {
            server_ = std::make_shared<server::RoombaServer>(8000);
            control_ = std::make_shared<RoombaControl>("/dev/ttyUSB0", RoombaControl::b115200);

            setState(initial);
        }

        /**
         * @return A shared pointer that owns the server object.
         */
        std::shared_ptr<server::RoombaServer> getServer() const { return server_; }

        /**
         * @return A shared pointer that owns the roomba control object
         */
        std::shared_ptr<RoombaControl> getControl() const { return control_; }

    private:
        std::shared_ptr<server::RoombaServer> server_;
        std::shared_ptr<RoombaControl> control_;
    };

    namespace states {
        /**
         * @brief State class that starts the server and connects the roomba serial. Next state is WaitForCmd if
         * succesful, Exit if failed.
         */
        class Initialise : public statemachine::State {
        public:
            ~Initialise() {}

            void handle(const std::shared_ptr<statemachine::Context> &context) override;
        };

        /**
         * @brief State class that waits for a signal from a PC or website
         */
        class WaitMode : public statemachine::State {
        public:
            ~WaitMode() {}

            void handle(const std::shared_ptr<statemachine::Context> &context) override;
        };

        /**
         * @brief State class that handles the cleaning.
         */
        class Clean : public statemachine::State {
        public:
            ~Clean() {}

            void handle(const std::shared_ptr<statemachine::Context> &context) override;
        };

        /**
         * @brief State class that shuts down the program. It closes the server and serial port.
         */
        class ShutDown : public statemachine::State {
        public:
            ~ShutDown() {}

            void handle(const std::shared_ptr<statemachine::Context> &context) override;
        };
    }
}

#endif //ROOMBACONTROLLER_PROCESSING_H
