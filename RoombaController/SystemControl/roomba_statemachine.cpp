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

    cout << "Waiting for signal from PC or webapp" << endl;

    // roomba starts manually if ENTER key is pressed
    thread cli([]{
        cin.ignore();

        unique_lock<std::mutex> lk(globals::mut_roomba_session);
        globals::roomba_session = globals::MAN;
        globals::cv_roomba_session.notify_one();
    });

    // roomba starts pc or web session if the server notified the condition variable
    unique_lock<std::mutex> lk(globals::mut_roomba_session);
    globals::cv_roomba_session.wait(lk);

    cli.detach();

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
