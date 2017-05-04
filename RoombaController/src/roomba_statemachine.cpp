//
// Created by jamie on 4/11/17.
//
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "roomba_statemachine.h"

using namespace std;
using namespace systemcontrol;
using namespace states;
using namespace Poco;

void Initialise::handle(const shared_ptr<statemachine::Context> &context) {
    auto rmbContext = static_pointer_cast<RoombaStateContext>(context);
    auto rmbControl = rmbContext->getControl();
    auto rmbServer = rmbContext->getServer();
    auto &logger = rmbContext->getLogger();

    rmbServer->run();

    if(rmbServer->started()) logger.information("Server started");
    if(rmbControl->init() < 0) logger.error("Serial port failed to connect to the roomba");

    context->setState(make_shared<WaitForSession>());
}

void WaitForSession::handle(const shared_ptr<statemachine::Context> &context) {
    auto rmbContext = static_pointer_cast<RoombaStateContext>(context);
    auto control = rmbContext->getControl();
    auto &logger = rmbContext->getLogger();

    logger.information("Waiting for signal from SESSION or webapp...");

    globals::roomba_session = globals::IDLE;

    // roomba starts manually if ENTER key is pressed
    thread cli([]{
        cin.ignore();

        unique_lock<std::mutex> lk(globals::mut_roomba_session);
        globals::roomba_session = globals::AUTO;
        globals::cv_roomba_session.notify_one();
    });

    // roomba starts pc or web session if the server notified the condition variable
    unique_lock<std::mutex> lk(globals::mut_roomba_session);
    globals::cv_roomba_session.wait(lk);

    cli.detach();

    switch (globals::roomba_session){
        case globals::AUTO:
            rmbContext->setState(make_shared<Clean>());
            break;

        case globals::PC_WEB:
            rmbContext->setState(make_shared<Session>());
            break;

        default:
            rmbContext->setState(make_shared<ShutDown>());
            logger.fatal("Invalid session");
            break;
    }
}

void Session::handle(const shared_ptr<statemachine::Context> &context) {
    // use local namespace for convenience
    using namespace globals;

    auto rmbContext = static_pointer_cast<RoombaStateContext>(context);
    auto rmbControl = rmbContext->getControl();
    auto &logger = rmbContext->getLogger();
    boost::asio::io_service io;

    logger.information("PC/Web session started");

    while(roomba_session == PC_WEB) {
        boost::asio::deadline_timer loopFrequency(io, boost::posix_time::milliseconds(33));
        unique_lock<std::mutex> param_lk(rmbPrm.mutex());
        unique_lock<std::mutex> event_lk(server_context.mutex());

        switch (server_context.getEvent()) {
            case ServerContext::E_EXIT:
                roomba_session = IDLE;
                logger.information("Exit session");
                break;

            case ServerContext::E_RIGHT:
                rmbControl->setRotation(static_cast<int>(300 * server_context.getWheelSpeed()), 0xFFFF);
                break;

            case ServerContext::E_LEFT:
                rmbControl->setRotation(static_cast<int>(300 * server_context.getWheelSpeed()), 0x0001);
                break;

            case ServerContext::E_BACKWARD:
                rmbControl->setRotation(static_cast<int>(-500 * server_context.getWheelSpeed()), 0x8000);
                break;

            case ServerContext::E_FORWARD:
                rmbControl->setRotation(static_cast<int>(500 * server_context.getWheelSpeed()), 0x8000);
                break;

            case ServerContext::E_FORWARD_LEFT: //
                rmbControl->setRotation(static_cast<int>(500 * server_context.getWheelSpeed()), 1000);
                break;

            case ServerContext::E_FORWARD_RIGHT:
                rmbControl->setRotation(static_cast<int>(500 * server_context.getWheelSpeed()), -1000);
                break;

            case ServerContext::E_BACKWARD_LEFT:
                rmbControl->setRotation(static_cast<int>(-500 * server_context.getWheelSpeed()), -1000);
                break;

            case ServerContext::E_BACKWARD_RIGHT:
                rmbControl->setRotation(static_cast<int>(-500 * server_context.getWheelSpeed()), 1000);
                break;

            case ServerContext::E_STOP:
                rmbControl->setRotation(0, 0x8000);
                break;

            default:
                break;
        }

        rmbControl->setBrushes(static_cast<unsigned char>(server_context.getBrushSpeed()));

        param_lk.unlock();
        event_lk.unlock();
        loopFrequency.wait();
    }

    context->setState(make_shared<WaitForSession>());
}

void Clean::handle(const shared_ptr<statemachine::Context> &context) {
    // use local namespace for convenience
    using namespace globals;

    auto rmbContext = static_pointer_cast<RoombaStateContext>(context);
    auto rmbControl = rmbContext->getControl();
    auto &logger = rmbContext->getLogger();
    boost::asio::io_service io;

    logger.information("Cleaning started");

    while(roomba_session != PC_WEB) {
        boost::asio::deadline_timer loopFrequency(io, boost::posix_time::milliseconds(33));
        unique_lock<std::mutex> param_lk(rmbPrm.mutex());

        // calculate dt
        // read sensors
        // run algorithm
        // control roomba

        param_lk.unlock();
        loopFrequency.wait();
    }

    context->setState(make_shared<WaitForSession>());
}

void ShutDown::handle(const shared_ptr<statemachine::Context> &context) {
    auto rmbContext = static_pointer_cast<RoombaStateContext>(context);
    auto rmbControl = rmbContext->getControl();
    auto rmbServer = rmbContext->getServer();

    rmbServer->stop();
    rmbControl->disconnect();

    context->setState(nullptr);
}
