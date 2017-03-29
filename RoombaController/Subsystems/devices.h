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
        Device(io::SerialPort &serial, const std::string &id) :
                id_(id),
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
         * @brief Sends data to the roomba.
         * @param cmd The command opcode of the device.
         * @param data The data to be sent
         */
        void sendData(unsigned char cmd, const io::byteVector &data) {
            serial_.writeByte(cmd);
            serial_.writeVector(data);
        }

        /**
         * @return Id of the device
         */
        std::string getId() const { return id_; }

    private:
        std::string id_;
        io::SerialPort serial_;
    };

    /// TODO
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
        Motor(io::SerialPort &serial, const std::string &id) :
                Device(serial, id) {}

        /**
         * @brief Destructor sets the device idle.
         */
        virtual ~Motor() {}

        /**
         * @brief Sets the device idle.
         */
        virtual void reset() override {

        }
    };

    /// TODO
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
        Leds(io::SerialPort &serial, const std::string &id) :
                Device(serial, id) {}

        /**
         * @brief Destructor sets the device idle.
         */
        virtual ~Leds() {}

        /**
         * @brief Sets the device idle.
         */
        virtual void reset() override {

        }
    };

    /// TODO
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
        Speaker(io::SerialPort &serial, const std::string &id) :
                Device(serial, id) {}

        /**
         * @brief Destructor sets the device idle.
         */
        virtual ~Speaker() {}

        /**
         * @brief Sets the device idle.
         */
        virtual void reset() override {

        }
    };
}

#endif //ROOMBACONTROLLER_DEVICES_H
