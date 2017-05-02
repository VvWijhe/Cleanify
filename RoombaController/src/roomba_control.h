//
// Created by victor on 27.03.17.
//

#ifndef ROOMBACONTROLLER_ROOMBACONTROLLER_H
#define ROOMBACONTROLLER_ROOMBACONTROLLER_H

#include <vector>
#include <map>
#include <string>
#include <memory>

#include "serial.h"

namespace systemcontrol {
    class RoombaControl {
    public:
        typedef enum : int {
            red, blue, green, orange
        } color_t;


        typedef enum : speed_t {
            b300 = B300,
            b600 = B600,
            b1200 = B1200,
            b2400 = B2400,
            b4800 = B4800,
            b9600 = B9600,
            b19200 = B19200,
            b38400 = B38400,
            b57600 = B57600,
            b115200 = B115200
        } baud_t;

        typedef enum : unsigned char {
            Reset = 7,
            Start = 128,
            Set_Baud = 129,
            Control = 130,
            Safe = 131,
            Full = 132,
            Power = 133,
            Spot = 134,
            Clean = 135,
            Max_Clean = 136,
            Drive = 137,
            Seek_Dock = 143,
            Pwm_Brushes = 144,
            Drive_Wheels = 145,

            Stop = 173

        } commands_t;

        struct parameters {
            int Drive_speed;
            int Drive_rotation;
            int Brushes_speed;
            color_t color;


        } par_t;

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
        void setBaud();

        void disconnect();

        /**
         * @brief reset the device by restarting it
         */
        void resetDevices();

        /**
         * @brief fills in roombacontrol function from algorithm
         * @param parameters struct from algorithm
         */

        void setDevices(parameters par);

        /**
         * set the rotation of the roomba without forward movement.
         * the value speed must be between -100 and 100, radial must be between -2000 and 2000.
         * if the roomba must turn around itself set radius to clockwise:-1 counterclockwise:1
         */
        void setRotation(int speed, int radial);

        /**
         * @brief This functions sets the main led of the roomba.
         * @param color: red, blue, green, orange
         */
        void setLed(color_t color);

        /**
         * @brief This function set the brushes and vacuum
         * @param PWM: 0 for brushes of and 127 for full power
         */
        void setBrushes(unsigned char PWM);


        /**
         * @brief This functions sends simple commands
         * @param command: fill in a commands_t command
         */
        void sendCommands(commands_t command);

        void beep();

        /// TODO
        void readSensors();

    private:
        io::SerialPort serial_;

    };
}


#endif //ROOMBACONTROLLER_ROOMBACONTROLLER_H
