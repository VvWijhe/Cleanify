//
// Created by victor on 27.03.17.
//

#ifndef ROOMBACONTROLLER_ROOMBACONTROLLER_H
#define ROOMBACONTROLLER_ROOMBACONTROLLER_H

#include <vector>
#include <map>
#include <string>
#include <memory>

#include "../Subsystems/devices.h"
#include "../IO/serial.h"
#include "commands.h"


namespace systemControl {
    class RoombaControl {
    public:
        typedef enum : int {
            wheels, rotation, leds
        } devices_t;

        typedef enum : int {
            red, blue, green, orange
        } color_t;

        typedef enum : int {
            b19200, b115200
        } baud_t;

        RoombaControl(std::string usbName, speed_t baud);

        ~RoombaControl();

        /**
         * @brief Initialize the roomba by setting it in the right state.
         * @return 1 if succesfull, -1 if failed
         */
        int init();

        /**
         * @brief Sets the baudrate.
         * @param baud Choices: 19200 and 115200
         */
        void setBaud(baud_t baud);

        /**
         * @brief reset the device by restarting it
         */
        void resetDevices();

        /**
         * @brief Sends bytes in a vector to the roomba.
         * @param data
         * @return -1 if failed, 1 if succesfull.
         */
        int sendData(const std::vector<unsigned char> &data);

        /**
         * @brief Control the roomba by changing the speed of each wheel seperately.
         * @param ls Speed of left wheel between -100 and 100.
         * @param rs Speed of right wheel between -100 and 100.
         */
        void setWheels(short ls, short rs);

        /**
         * @brief Sets the speed of both wheels.
         * @param speed Speed of the wheels between -100 and 100.
         */
        void setWheels(short speed);

        /**
         * set the rotation of the roomba without forward movement.
         * the value speed must be between -100 and 100, radial must be between -2000 and 2000.
         * if the roomba must turn around itself set radius to clockwise:-1 counterclockwise:1
         */
        void setRotation(short speed, short radial);

        /**
         * @brief This functions sets the main led of the roomba.
         * @param color: red, blue, green, orange
         */
        void setLed(color_t color);

        /// TODO
        void readSensors();

        const std::map<std::string, unsigned char> getCmds();

    private:
        std::map<devices_t, subsystems::Device *> devices_;
        io::SerialPort serial_;
        Commands commands_;
    };


}


#endif //ROOMBACONTROLLER_ROOMBACONTROLLER_H
