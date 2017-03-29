//
// Created by victor on 27.03.17.
//

#ifndef ROOMBACONTROLLER_ROOMBACONTROLLER_H
#define ROOMBACONTROLLER_ROOMBACONTROLLER_H

#include <vector>
#include <map>
#include <string>
#include "../IO/serial.h"
#include "commands.h"



namespace systemControl {
    class RoombaControl {

    public:

        RoombaControl();

        ///initialize the roomba by setting it in the right state
        int init();

        ///reset the device by restarting it
        void resetDevices();

        /// send the vector with data to the roomba via serial.cpp
        int sendData(const std::vector<unsigned char>&);


        /// controll the roomba by changing the speed of each wheel seperately.
        /// the value ls and rs must be between -100 and 100.
        void setWheels(short ls, short rs);

        /// set the forward speed of the roomba.
        /// the value speed must be between -100 and 100.
        void setWheels(short speed);

        /// set the rotation of the roomba without forward movement.
        /// the value speed must be between -100 and 100, direction must be either right or left.
        void setRotation(short speed, enum direction);

        /**
         * this functions sets the main led of the roomba.
         * you must choose between: red
         *                          blue
         *                          green
         *                          orange
         */
        void setLed(enum color);

        ///
        void readSensors();

        const std::map<std::string, unsigned char> getCmds();

    private:

        io::SerialPort serial_ ;

    };


}




#endif //ROOMBACONTROLLER_ROOMBACONTROLLER_H
