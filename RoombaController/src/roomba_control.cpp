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
    //setBaud();
    //beep();




    unsigned char duur = 32;
    vector<unsigned char> start = {128, 131};
    vector<unsigned char> panzer = {140, 0, 11, 70, duur, 74, static_cast<unsigned char>(duur*2), 64, duur, 65, static_cast<unsigned char>(duur), 64, static_cast<unsigned char>(duur*2),
                                    62, duur, 60, duur, 67, static_cast<unsigned char>(duur*2), 76, duur, 74, static_cast<unsigned char>(duur/2), 72, duur};
    vector<unsigned char> panzer2 = {140,1,11, 72, duur, 74, static_cast<unsigned char>(duur*2), 69, duur, 69, static_cast<unsigned char>(duur/2), 69, static_cast<unsigned char>(duur*2),
                                     67, duur, 65, duur, 64, static_cast<unsigned char>((duur/2)*3), 67, duur, 65, static_cast<unsigned char>(duur/2), 64, duur};

    serial_.writeVector(panzer);
    serial_.writeVector(panzer2);

    serial_.writeVector({141, 0});
    this_thread::sleep_for(chrono::milliseconds(8000));
    serial_.writeVector({141, 1});

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

void RoombaControl::setDevices(parameters par) {
    setRotation(par.Drive_speed, par.Drive_rotation);
    setBrushes(par.Brushes_speed);
    setLed(par.color);
}

void RoombaControl::setRotation(int speed, int radial) {

    auto vel_hb = static_cast<unsigned char>((speed >> 8) & 0xFF);
    auto vel_lb = static_cast<unsigned char>(speed & 0xFF);
    auto rad_hb = static_cast<unsigned char>((radial >> 8) & 0xFF);
    auto rad_lb = static_cast<unsigned char>(radial & 0xFF);

    serial_.writeVector({Drive, vel_hb, vel_lb, rad_hb, rad_lb});
    //serial_.writeVector({Drive, 0x01, 0xF4, 0x00, 0x01});
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

void RoombaControl::beep() {
    serial_.writeVector({Start, Full, 140, 0, 1, 62, 32, 141, 0});
}
