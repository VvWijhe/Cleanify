//
// Created by jamie on 3/28/17.
//

#ifndef ROOMBACONTROLLER_DEVICES_H
#define ROOMBACONTROLLER_DEVICES_H

#include <string>

#include "../IO/serial.h"

namespace subsystems {
    /**
     * @brief Base class for devices in the roomba. Device classes can send data trough a serial port.
     */
    class Device {
    public:
        /**
         * @brief Device constructor.
         * @param serial A serial port object.
         * @param id The name of the device.
         */
        Device(io::SerialPort *serial, unsigned char opcode) :
                opcode_(opcode),
                serial_(serial) {}

        /**
         * @brief The destructor does nothing.
         */
        virtual ~Device() = default;

        /**
         * @brief Sets all devices idle.
         */
        virtual void reset() = 0;

        /**
         * @brief Sends a dataframe to the roomba.
         * @param data The data to be sent
         */
        void sendData(const io::byteVector &data) {
            serial_->writeByte(opcode_);
            serial_->writeVector(data);
        }

    private:
        unsigned char opcode_;
        io::SerialPort *serial_;
    };

    /**
     * @brief Roomba device for controlling the motors.
     */
    class Motor : public Device {
    public:
        /**
         * @brief Constructor.
         * @param serial A serial port object.
         * @param id The name of the device.
         */
        Motor(io::SerialPort *serial, unsigned char opcode) :
                Device(serial, opcode) {}

        /**
         * @brief Destructor sets the device idle.
         */
        virtual ~Motor() {
            reset();
        }

        /**
         * @brief Sets the device idle.
         */
        virtual void reset() override {
            sendData({0, 0, 0, 0});
        }
    };

    /**
     * @brief Roomba device for controlling the leds.
     */
    class Leds : public Device {
    public:
        /**
         * @brief Constructor.
         * @param serial A serial port object.
         * @param id The name of the device.
         */
        Leds(io::SerialPort *serial, unsigned char opcode) :
                Device(serial, opcode) {}

        /**
         * @brief Destructor sets the device idle.
         */
        virtual ~Leds() {
            reset();
        }

        /**
         * @brief Sets the device idle.
         */
        virtual void reset() override {
            sendData({0, 0, 0});
        }
    };

    /**
     * @brief Roomba device for controlling the leds.
     */
    class Speaker : public Device {
    public:
        /**
         * @brief Constructor.
         * @param serial A serial port object.
         * @param id The name of the device.
         */
        Speaker(io::SerialPort *serial, unsigned char opcode) :
                Device(serial, opcode) {}

        /**
         * @brief Destructor sets the device idle.
         */
        virtual ~Speaker() {
            reset();
        }

        /**
         * @brief Sets the device idle.
         */
        virtual void reset() override {
            // empty
        }
    };
}

#endif //ROOMBACONTROLLER_DEVICES_H
