//
// Created by jamie on 4/11/17.
//

#include "roomba_statemachine.h"

using namespace std;
using namespace systemcontrol;
using namespace states;

void Initialise::handle(const shared_ptr<statemachine::Context> &context) {
    auto rmbContext = static_pointer_cast<RoombaStateContext>(context);
    auto rmbControl = rmbContext->getControl();
    auto rmbServer = rmbContext->getServer();

    rmbServer->run();
    rmbControl->init();

    cout << "initialise " << context->getEvent() << endl;
    context->setNextState(make_shared<WaitForCmd>());
}

void WaitForCmd::handle(const shared_ptr<statemachine::Context> &context) {
    auto rmbContext = static_pointer_cast<RoombaStateContext>(context);
    auto control = rmbContext->getControl();

    cout << "wait " << context->getEvent() << endl;
    context->setNextState(make_shared<Clean>());
}

void Clean::handle(const shared_ptr<statemachine::Context> &context) {
    cout << "clean " << context->getEvent() << endl;
    context->setNextState(make_shared<ShutDown>());
}

void ShutDown::handle(const shared_ptr<statemachine::Context> &context) {
    auto rmbContext = static_pointer_cast<RoombaStateContext>(context);
    auto rmbControl = rmbContext->getControl();
    auto rmbServer = rmbContext->getServer();

    rmbServer->stop();

    context->setNextState(nullptr);
}
