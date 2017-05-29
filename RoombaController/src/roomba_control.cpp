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

    serial_.writeVector({Drive, vel_hb, vel_lb, rad_hb, rad_lb, Control});

    //this_thread::sleep_for(chrono::milliseconds(100));
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
    static int attempts;

    if(serial_.readAll(streamBuffer_) < 0 && attempts < 3) {
        attempts++;
        return -1;
    } else if(attempts == 3){
        attempts = 0;
        return -2;
    }

    auto validFrame = Sensors::lastValidFrame(streamBuffer_);

    if(validFrame.size() == 0) return -3;

    auto result = sensorBuffer.parsedata(validFrame);

    return 0;

//    condition_variable cv;
//    mutex mut;
//    io::byteVector buffer;
//    thread t([this, &buffer, &cv, &sensorBuffer]() -> void {
//        if (this->serial_.readAll(buffer) < 0) return;
//
//        cv.notify_all();
//    });
//
//    unique_lock<mutex> lk(mut);
//    if (cv.wait_for(lk, chrono::milliseconds(5000)) == cv_status::timeout) {
//        t.detach();
//        return -1;
//    }
//
//    auto result = sensorBuffer.parsedata(buffer);
//    t.detach();
//
//    return 0;
}

void RoombaControl::setBrushes(unsigned char pwm) {
    serial_.writeVector({Pwm_Brushes, pwm, pwm, pwm});

}

void RoombaControl::sendCommands(commands_t command) {
    serial_.writeByte(command);

}

void RoombaControl::beep() {
    serial_.writeVector({Start, Control, Safe, 140, 0, 1, 62, 32, 141, 0});
}

void RoombaControl::startStream() {
    serial_.writeVector(Sensors::createvectorstream({Light_bumper, Bumps_wheeldrops, Battery_charge}));
}

void RoombaControl::stopStream() {
    serial_.writeVector({150, 0});
}
