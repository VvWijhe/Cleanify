//
// Created by jamie on 4/11/17.
//

#include "main_process.h"

using namespace systemControl;
using namespace std;

RoombaProcessing::RoombaProcessing() {
    add(init_s, std::make_shared<State>(init));
    add(test_s, std::make_shared<State>(test));
}

static void RoombaProcessing::init(State *currentState) {
    cout << "init" << endl;

    currentState->setNextState(test_s);
    currentState->setEvent(timeout_e);
}

static void RoombaProcessing::test(State *currentState) {
    cout << "test" << endl;

    switch (currentState->event()) {
        case timeout_e:
            cout << "timeout" << endl;
            currentState->setNextState(State::nstate);
            break;

        default:
            currentState->setNextState(State::nstate);
            break;
    }
}
