//
// Created by victor on 29.03.17.
//

#include "roomba_control.h"

using namespace std;
using namespace systemcontrol;

RoombaControl::RoombaControl(std::string usbName, speed_t baud) :
        serial_(usbName, baud) {
    currentMotor_ = 0;
}

RoombaControl::~RoombaControl() {}

int RoombaControl::init() {
    if (serial_.connect() != 1) {
        return -1;
    }

    serial_.writeVector({128, 130});

    return 0;
}

void RoombaControl::setBaud(RoombaControl::baud_t baud) {


    serial_.writeVector({129,});
}

void RoombaControl::disconnect() {
    serial_.disconnect();
}

void RoombaControl::resetDevices() {
    serial_.writeByte({7});
}

void RoombaControl::setWheels(short ls, short rs) {

    auto hexl_hb = static_cast<unsigned char>(((ls * 5) >> 8) & 0xFF);
    auto hexl_lb = static_cast<unsigned char>((ls * 5) & 0xFF);
    auto hexr_hb = static_cast<unsigned char>(((rs * 5) >> 8) & 0xFF);
    auto hexr_lb = static_cast<unsigned char>((rs * 5) & 0xFF);

    serial_.writeVector({145, hexl_hb, hexl_lb, hexr_hb, hexr_lb});
}

void RoombaControl::setWheels(short speed) {

    unsigned char hexl_hb = ((speed * 5) >> 8) & 0xFF;
    unsigned char hexl_lb = (speed * 5) & 0xFF;

    serial_.writeVector({145, hexl_hb, hexl_lb, hexl_hb, hexl_lb});
}

void RoombaControl::setRotation(short speed, short radial) {

    unsigned char vel_hb = ((speed * 5) >> 8) & 0xFF;
    unsigned char vel_lb = (speed * 5) & 0xFF;
    unsigned char rad_hb = ((radial * 5) >> 8) & 0xFF;
    unsigned char rad_lb = (radial * 5) & 0xFF;

    serial_.writeVector({137, vel_hb, vel_lb, rad_hb, rad_lb});
}

void RoombaControl::setLed(color_t color) {
    switch (color) {
        case red:

            break;
        case blue:

            break;
        case green:

            break;
        case orange:

            break;
        default:
            //error
            break;
    }
}

void RoombaControl::readSensors() {

}

void RoombaControl::setMotors(int PWM) {
    unsigned char pwm = PWM;
    serial_.writeVector({145, pwm, pwm, pwm});

}

void RoombaControl::sendCommands(int command) {

    unsigned char com = command;
    serial_.writeByte(com);

}
