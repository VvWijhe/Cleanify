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
    if(serial_.connect()< 0){
        cerr<<"not connected"<< endl;
    }

    serial_.writeByte(128);
    serial_.writeByte(130);
    serial_.writeByte(135);

    return 0;
}

void RoombaControl::setBaud(RoombaControl::baud_t baud) {

}

void RoombaControl::resetDevices() {

}

int RoombaControl::sendData(const std::vector<unsigned char> &data) {

    return 1;
}

void RoombaControl::setWheels(short ls, short rs) {
    io::byteVector data;

    auto hexl_hb = static_cast<unsigned char>(((ls * 5) >> 8) & 0xFF);
    auto hexl_lb = static_cast<unsigned char>((ls * 5) & 0xFF);
    auto hexr_hb = static_cast<unsigned char>(((rs * 5) >> 8) & 0xFF);
    auto hexr_lb = static_cast<unsigned char>((rs * 5) & 0xFF);

    data.push_back({145});
    data.push_back(hexl_hb);
    data.push_back(hexl_lb);
    data.push_back(hexr_hb);
    data.push_back(hexr_lb);

    serial_.writeVector(data);


}

void RoombaControl::setWheels(short speed) {
    io::byteVector data;

    unsigned char hexl_hb = ((speed * 5) >> 8) & 0xFF;
    unsigned char hexl_lb = (speed * 5) & 0xFF;

    data.push_back({145});
    data.push_back(hexl_hb);
    data.push_back(hexl_lb);
    data.push_back(hexl_hb);
    data.push_back(hexl_lb);

    serial_.writeVector(data);

}

void RoombaControl::setRotation(short speed, short radial) {
    io::byteVector data = {};

    unsigned char vel_hb = ((speed * 5) >> 8) & 0xFF;
    unsigned char vel_lb = (speed * 5) & 0xFF;
    unsigned char rad_hb = ((radial * 5) >> 8) & 0xFF;
    unsigned char rad_lb = (radial * 5) & 0xFF;

    data.push_back(137);
    data.push_back(vel_hb);
    data.push_back(vel_lb);
    data.push_back(rad_hb);
    data.push_back(rad_lb);

    serial_.writeVector(data);


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

const std::map<std::string, unsigned char> RoombaControl::getCmds() {
    return commands_.getMap();
}
