//
// Created by jamie on 4/21/17.
//

#ifndef ROOMBACONTROLLER_GLB_EVENTS_H
#define ROOMBACONTROLLER_GLB_EVENTS_H

#include <mutex>

namespace globals {
    class ServerContext {
    public:
        enum server_events {
            E_NO,
            E_LEFT, E_RIGHT, E_FORWARD, E_BACKWARD, E_STOP,
            E_BRUSH_ON, E_BRUSH_OFF, E_EXIT, E_MUSIC, E_CLEAN, E_SPOT, E_DOCK,
            E_LED_GREEN, E_LED_ORANGE, E_LED_RED, E_LED_BLUE
        };

        ServerContext() : brushSpeed_(0),
                          wheelSpeed_(0.0)
        {}

        void setEvent(server_events event) { event_ = event; }

        server_events getEvent() {
            auto tmp = event_;
            event_ = E_NO;
            return tmp;
        }

        void setWheelSpeed(double speed) {
            wheelSpeed_ = speed;
        }

        void setBrushSpeed(unsigned int speed) {
            brushSpeed_ = speed;
        }

        double getWheelSpeed() const {
            return wheelSpeed_;
        }

        unsigned int getBrushSpeed() const {
            return brushSpeed_;
        }

        std::mutex &mutex() {
            return mutex_;
        }

        void operator=(server_events event) {
            event_ = event;
        }

    private:
        unsigned int brushSpeed_;
        double wheelSpeed_;
        std::mutex mutex_;
        server_events event_;
    };

    extern ServerContext server_context;
}

#endif //ROOMBACONTROLLER_GLB_EVENTS_H
