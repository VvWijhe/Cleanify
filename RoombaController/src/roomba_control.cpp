//
// Created by victor on 29.03.17.
//

#include "roomba_control.h"

using namespace std;
using namespace systemcontrol;

RoombaControl::RoombaControl(std::string usbName, speed_t baud) :
        serial_(usbName, baud) {

}

RoombaControl::~RoombaControl() {}

int RoombaControl::init() {
    if (serial_.connect() != 1) {
        return -1;
    }

    serial_.writeVector({128, 130, 140, 0, 1 , 62, 32, 141, 0});

    return 0;
}

void RoombaControl::setBaud() {


    serial_.writeVector({Set_Baud, 11});
}

void RoombaControl::disconnect() {
    serial_.disconnect();
}

void RoombaControl::resetDevices() {
    serial_.writeByte(Reset);
}

void RoombaControl::setWheels(int ls, int rs) {

    auto hexl_hb = static_cast<unsigned char>(((ls * 5) >> 8) & 0xFF);
    auto hexl_lb = static_cast<unsigned char>((ls * 5) & 0xFF);
    auto hexr_hb = static_cast<unsigned char>(((rs * 5) >> 8) & 0xFF);
    auto hexr_lb = static_cast<unsigned char>((rs * 5) & 0xFF);

    serial_.writeVector({Drive_Wheels, hexl_hb, hexl_lb, hexr_hb, hexr_lb});
}

void RoombaControl::setWheels(int speed) {

    auto hexl_hb = static_cast<unsigned char>((speed * 5 >> 8) & 0xFF);
    auto hexl_lb = static_cast<unsigned char>(speed * 5 & 0xFF);

    serial_.writeVector({Drive_Wheels, hexl_hb, hexl_lb, hexl_hb, hexl_lb});
}

void RoombaControl::setRotation(int speed, int radial) {

    auto vel_hb = static_cast<unsigned char>((speed * 5 >> 8) & 0xFF);
    auto vel_lb = static_cast<unsigned char>(speed * 5 & 0xFF);
    auto rad_hb = static_cast<unsigned char>((radial * 5 >> 8) & 0xFF);
    auto rad_lb = static_cast<unsigned char>(radial * 5 & 0xFF);

    serial_.writeVector({Drive, vel_hb, vel_lb, rad_hb, rad_lb});
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

void RoombaControl::setBrushes(unsigned char PWM) {
    serial_.writeVector({Pwm_Brushes, PWM, PWM, PWM});

}

void RoombaControl::sendCommands(commands_t command) {
    serial_.writeByte(command);

}
