//
// Created by jamie on 4/11/17.
//

#include "roomba_statemachine.h"


using namespace std;
using namespace systemcontrol;
using namespace states;
using namespace globals;
using namespace Poco;

void Initialise::handle(const shared_ptr<statemachine::Context> &context) {
    auto rmbContext = static_pointer_cast<RoombaStateContext>(context);
    auto rmbControl = rmbContext->getControl();
    auto rmbServer = rmbContext->getServer();
    auto &logger = rmbContext->getLogger();

    rmbServer->run();
    if(rmbServer->started()) logger.information("Server started");

    if(rmbControl->init() < 0) logger.error("Serial port failed to connect to the roomba");

    context->setState(make_shared<WaitMode>());
}

void WaitMode::handle(const shared_ptr<statemachine::Context> &context) {
    auto rmbContext = static_pointer_cast<RoombaStateContext>(context);
    auto control = rmbContext->getControl();
    auto &logger = rmbContext->getLogger();

    logger.information("Waiting for signal from SESSION or webapp...");

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

    switch (globals::roomba_session){
        case globals::MAN:
            rmbContext->setState(make_shared<Manuel>());
            break;

        case globals::SESSION:
            rmbContext->setState(make_shared<Session>());
            break;

        default:
            logger.fatal("Invalid state, shutting down");
            rmbContext->setState(make_shared<ShutDown>());
            break;
    }
}

void Manuel::handle(const shared_ptr<statemachine::Context> &context) {
    cout << "Manuel " << globals::roomba_session << endl;


    auto rmbContext = static_pointer_cast<RoombaStateContext>(context);
    auto rmbControl = rmbContext->getControl();
    rmbControl->setMotors(roomba_param.getParameter(roomba_param.BRUSHES));
    rmbControl->setWheels(roomba_param.getParameter(roomba_param.M_LEFT),
                          roomba_param.getParameter(roomba_param.M_RIGHT));
    rmbControl->sendCommands(roomba_param.getParameter(roomba_param.COMMAND));

    cin.ignore();
    context->setState(make_shared<WaitMode>());
}

void Session::handle(const shared_ptr<statemachine::Context> &context) {
    cout << "Session " << globals::roomba_session << endl;

    auto rmbContext = static_pointer_cast<RoombaStateContext>(context);
    auto rmbControl = rmbContext->getControl();
    rmbControl->setMotors(roomba_param.getParameter(roomba_param.BRUSHES));
    rmbControl->setWheels(roomba_param.getParameter(roomba_param.M_LEFT),
                          roomba_param.getParameter(roomba_param.M_RIGHT));
    rmbControl->sendCommands(roomba_param.getParameter(roomba_param.COMMAND));

    cin.ignore();
    context->setState(make_shared<WaitMode>());
}



void ShutDown::handle(const shared_ptr<statemachine::Context> &context) {
    auto rmbContext = static_pointer_cast<RoombaStateContext>(context);
    auto rmbControl = rmbContext->getControl();
    auto rmbServer = rmbContext->getServer();

    rmbServer->stop();
    rmbControl->disconnect();

    context->setState(nullptr);
}
