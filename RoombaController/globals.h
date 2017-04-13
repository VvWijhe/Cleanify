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
    extern bool roomba_ready;
    extern std::mutex m_roomba_ready;
    extern std::condition_variable cv_roomba_ready;
}

#endif //ROOMBACONTROLLER_GLOBALS_H
