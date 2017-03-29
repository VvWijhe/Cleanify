//
// Created by victor on 29.03.17.
//

#include "roomba_control.h"

using namespace systemControl;

int RoombaControl::init() {


    return 0;
}

void RoombaControl::resetDevices() {

}

int RoombaControl::sendData(const std::vector<unsigned char> &) {


}

void RoombaControl::setWheels(short ls, short rs) {
    io::byteVector data;

    unsigned char hexl_hb = ((ls * 5) >> 8) & 0xFF;
    unsigned char hexl_lb = (ls * 5) & 0xFF;
    unsigned char hexr_hb = ((rs * 5) >> 8) & 0xFF;
    unsigned char hexr_lb = (rs * 5) & 0xFF;

    data.push_back(145);
    data.push_back(hexr_hb);
    data.push_back(hexr_lb);
    data.push_back(hexl_hb);
    data.push_back(hexl_lb);

    sendData(data);
}

void RoombaControl::setWheels(short speed) {
    io::byteVector data;

    unsigned char hexl_hb = ((speed * 5) >> 8) & 0xFF;
    unsigned char hexl_lb = (speed * 5) & 0xFF;
    unsigned char hexr_hb = hexl_hb;
    unsigned char hexr_lb = hexl_lb;

    data.push_back(145);
    data.push_back(hexr_hb);
    data.push_back(hexr_lb);
    data.push_back(hexl_hb);
    data.push_back(hexl_lb);

    sendData(data);

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




}

void RoombaControl::setLed(color_t color) {

    switch(color){
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

const std::map<std::string, unsigned char>  RoombaControl::getCmds() {


}