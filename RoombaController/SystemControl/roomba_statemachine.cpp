//
// Created by jamie on 4/11/17.
//

#include "roomba_statemachine.h"

#include "../globals.h"

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
    context->setState(make_shared<WaitMode>());
}

void WaitMode::handle(const shared_ptr<statemachine::Context> &context) {
    auto rmbContext = static_pointer_cast<RoombaStateContext>(context);
    auto control = rmbContext->getControl();

    // wait for pc website
    cout << "Waiting for signal from PC" << endl;

    unique_lock<std::mutex> lk(globals::mut_roomba_session);
    globals::cv_roomba_session.wait(lk);

    context->setState(make_shared<Clean>());
}

void Clean::handle(const shared_ptr<statemachine::Context> &context) {
    cout << "clean " << globals::roomba_session << endl;
    context->setState(make_shared<ShutDown>());
}

void ShutDown::handle(const shared_ptr<statemachine::Context> &context) {
    auto rmbContext = static_pointer_cast<RoombaStateContext>(context);
    auto rmbControl = rmbContext->getControl();
    auto rmbServer = rmbContext->getServer();

    rmbServer->stop();
    rmbControl->disconnect();

    context->setState(nullptr);
}
