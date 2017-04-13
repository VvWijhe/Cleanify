//
// Created by jamie on 4/13/17.
//

#include "globals.h"

bool globals::roomba_ready;
std::mutex globals::m_roomba_ready;
std::condition_variable globals::cv_roomba_ready;
