//
// Created by jamie on 4/13/17.
//

#include "glb_session.h"

using namespace globals;

session globals::roomba_session = IDLE;
std::mutex globals::mut_roomba_session;
std::condition_variable globals::cv_roomba_session;
