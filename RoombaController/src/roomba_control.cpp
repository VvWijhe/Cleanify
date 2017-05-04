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
    beep();


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

void RoombaControl::setRotation(int speed, int radius) {

    auto vel_hb = static_cast<unsigned char>((speed >> 8) & 0xFF);
    auto vel_lb = static_cast<unsigned char>(speed & 0xFF);
    auto rad_hb = static_cast<unsigned char>((radius >> 8) & 0xFF);
    auto rad_lb = static_cast<unsigned char>(radius & 0xFF);

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

int RoombaControl::readSensors(Sensors &sensorBuffer) {
    condition_variable cv;
    mutex mut;
    io::byteVector buffer;
    Sensors tmpSensor;

    thread t([this, &buffer, &cv]{
        this->serial_.readAll(buffer);
        cv.notify_all();
    });

    unique_lock<mutex> lk(mut);
    if(cv.wait_for(lk, chrono::milliseconds(1000)) == cv_status::timeout) return -1;

    t.detach();

    return 0;
}

void RoombaControl::setBrushes(unsigned char pwm) {
    serial_.writeVector({Pwm_Brushes, pwm, pwm, pwm});

}

void RoombaControl::sendCommands(commands_t command) {
    serial_.writeByte(command);

}

void RoombaControl::beep() {
    serial_.writeVector({Start, Full, 140, 0, 1, 62, 32, 141, 0});
}
