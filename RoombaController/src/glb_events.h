//
// Created by jamie on 4/21/17.
//

#ifndef ROOMBACONTROLLER_GLB_EVENTS_H
#define ROOMBACONTROLLER_GLB_EVENTS_H

#include <mutex>

namespace globals {
    class ServerEvents {
    public:
        enum server_events {
            E_NO,
            E_LEFT, E_RIGHT, E_FORWARD, E_BACKWARD, E_STOP,
            E_BRUSH, E_EXIT, E_MUSIC, E_CLEAN, E_SPOT, E_DOCK,
            E_LED_GREEN, E_LED_ORANGE, E_LED_RED, E_LED_BLUE
        };

        ServerEvents() {}

        void setEvent(server_events event) { event_ = event; }

        server_events getEvent() {
            auto tmp = event_;
            event_ = E_NO;
            return tmp;
        }

        std::mutex& mutex() {
            return mutex_;
        }

        void operator=(server_events event) {
            event_ = event;
        }

    private:
        std::mutex mutex_;
        server_events event_;
    };

    extern ServerEvents server_event;
}

#endif //ROOMBACONTROLLER_GLB_EVENTS_H
