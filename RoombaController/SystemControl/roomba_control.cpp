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

}

void RoombaControl::setWheels(short speed) {

}

void RoombaControl::setRotation(short speed, direction_t direction) {
    switch (direction) {

        case left:


            break;
        case right:


            break;

        default:
            //error
            break;

    }



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