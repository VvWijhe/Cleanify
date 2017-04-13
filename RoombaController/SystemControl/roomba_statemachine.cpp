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
    context->setNextState(make_shared<WaitMode>());
}

void WaitMode::handle(const shared_ptr<statemachine::Context> &context) {
    auto rmbContext = static_pointer_cast<RoombaStateContext>(context);
    auto control = rmbContext->getControl();

    // wait for pc website or press on enter
    thread cli([]{
        cout << "Waiting for signal from PC, website or press ENTER" << endl;
        cin.ignore();
        std::unique_lock<std::mutex> lk(globals::m_roomba_ready);
        globals::roomba_ready = true;
        globals::cv_roomba_ready.notify_one();
    });

    unique_lock<std::mutex> lk(globals::m_roomba_ready);
    globals::cv_roomba_ready.wait(lk);
    if (globals::roomba_ready) cout << "Roomba going to next state" << endl;
    cli.join();

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

    globals::roomba_ready = false;

    context->setNextState(make_shared<WaitMode>());
}
