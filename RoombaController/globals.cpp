//
// Created by jamie on 4/13/17.
//

#include "globals.h"

using namespace globals;

session globals::roomba_session = MAN;
std::mutex globals::mut_roomba_session;
std::condition_variable globals::cv_roomba_session;
