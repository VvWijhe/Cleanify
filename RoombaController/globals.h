//
// Created by jamie on 4/13/17.
//

#ifndef ROOMBACONTROLLER_GLOBALS_H
#define ROOMBACONTROLLER_GLOBALS_H

#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

namespace globals {
    enum session {
        IDLE, MAN, PC, WEB
    };
    extern session roomba_session;
    extern std::mutex mut_roomba_session;
    extern std::condition_variable cv_roomba_session;
}

#endif //ROOMBACONTROLLER_GLOBALS_H
