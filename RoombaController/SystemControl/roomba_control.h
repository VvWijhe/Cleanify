//
// Created by victor on 27.03.17.
//

#ifndef ROOMBACONTROLLER_ROOMBACONTROLLER_H
#define ROOMBACONTROLLER_ROOMBACONTROLLER_H

#include <vector>
#include <map>
#include <string>
#include <memory>

#include "../Serial/serial.h"
#include "commands.h"

namespace systemcontrol {
    class RoombaControl {
    public:
        typedef struct {
            int code;
            speed_t baud;
        } bauds_t;

        typedef enum : int {
            red, blue, green, orange
        } color_t;

        typedef enum : int {
            side = 1,
            vacuum = 2,
            main = 4,
            side_direction = 8,
            main_direction = 16,
            all = 15
        };

        typedef enum : speed_t {
            b300 = B300,
            b600 = B600,
            b1200 = B1200,
            b2400 = B2400,
            b4800 = B4800,
            b9600 = B9600,
            b14400 = B14400,
            b19200 = B19200,
            b28800 = B28800,
            b38400 = B38400,
            b57600 = B57600,
            b115200 = B115200}

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

        /**
         * @brief This function set the brushes and vacuum
         * @param motor: side, vacuum, main, side_direction, main_direction
         * @param state: on = 1, off = 0
         */
        void setMotors(char motor, bool state);

        /// TODO
        void readSensors();

        const std::map<std::string, unsigned char> getCmds();

        const char getMotors() const {return motors_;}
        void setMotors(char motors){motors_ = motors;}

    private:
        io::SerialPort serial_;
        Commands commands_;
        char motors_;
    };
}


#endif //ROOMBACONTROLLER_ROOMBACONTROLLER_H
