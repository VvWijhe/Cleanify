//
// Created by jamie on 4/11/17.
//

#include "roomba_process.h"

using namespace std;

void systemControl::WaitForCmd::handle(shared_ptr<statemachine::Context> context) {
    cout << "wait " << context->getEvent() << endl;
    context->setNextState(make_shared<Clean>());
}

void systemControl::Clean::handle(shared_ptr<statemachine::Context> context) {
    cout << "clean " << context->getEvent() << endl;
    context->setNextState(nullptr);
}
