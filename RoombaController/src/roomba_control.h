//
// Created by victor on 27.03.17.
//

#ifndef ROOMBACONTROLLER_ROOMBACONTROLLER_H
#define ROOMBACONTROLLER_ROOMBACONTROLLER_H

#include <vector>
#include <map>
#include <string>
#include <memory>

#include "sensorparser.h"
#include "serial.h"

namespace systemcontrol {
    /**
     * @brief Handles the controlling of the roomba. It contains functions that can set the wheels, brushes and leds.
     * A serial connection is required to control the Roomba. This class uses linux functions to use the serial port.
     */
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
        } parameters_t;

        /**
         * @brief Constructor sets initialises the serial connection.
         * @param usbName Path to the serial port.
         * @param baud The baudrate that is supported by the Roomba.
         */
        RoombaControl(std::string usbName, speed_t baud);

        /**
         * @brief Empty destructor.
         */
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

        /**
         * @brief Closes the serial connection.
         */
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
        void setRotation(int speed, int radius);

        /**
         * @brief This functions sets the main led of the roomba.
         * @param color: red, blue, green, orange
         */
        void setLed(color_t color);

        /**
         * @brief This function set the brushes and vacuum
         * @param pwm: 0 for brushes of and 127 for full power
         */
        void setBrushes(unsigned char pwm);


        /**
         * @brief This functions sends simple commands
         * @param command: fill in a commands_t command
         */
        void sendCommands(commands_t command);

        /**
         * @brief Lets the Roomba do one beep.
         */
        void beep();

        void startStream();

        void stopStream();

        /**
         * @brief Requests sensordata and parses the data that is requested. If it has not received data after 800 ms,
         * it will return an error.
         * @param sensorBuffer A Sensor object where the parsed data will be stored.
         * @return -3 if the sensordata is not complete yet,
         * -2 if no data was available in 3 attempts, 0 if succesfull
         */
        int readSensors(Sensors &sensorBuffer);

        void startStream();

    private:
        io::SerialPort serial_;
        std::vector<unsigned char> streamBuffer_;
    };
}


#endif //ROOMBACONTROLLER_ROOMBACONTROLLER_H
