//
// Created by jamie on 4/11/17.
//

#include "main_process.h"

using namespace systemControl;
using namespace std;

RoombaProcessing::RoombaProcessing() {
    add(init_s, std::make_shared<State>(init));
    add(waitForMode_s, std::make_shared<State>(waitForMode));
}

void RoombaProcessing::init(State *currentState) {
    cout << "init" << endl;

    currentState->setNextState(waitForMode_s);
}

void RoombaProcessing::waitForMode(State *currentState) {

}

void RoombaProcessing::clean(State *currentState) {

}

void RoombaProcessing::spot(State *currentState) {

}
