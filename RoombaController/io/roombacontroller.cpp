//
// Created by victor on 27.03.17.
//

#include "roombacontroller.h"



void io::roombacontroller::setWheels(short ls, short rs) {



}

void io::roombacontroller::setWheels(short speed) {

}

void io::roombacontroller::setRotation(short speed, enum direction) {

}

void io::roombacontroller::setLed(enum color) {

}

void io::roombacontroller::readSensors() {
    byteVector empty;

    Sci.sendCommand("Stream", empty);

}

io::roombacontroller::roombacontroller(const io::RoombaSCI &Sci) : Sci(Sci) {}
