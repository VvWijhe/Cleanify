//
// Created by victor on 13.03.17.
//

#ifndef ROOMBACONTROLLER_ROOMBASCI_H
#define ROOMBACONTROLLER_ROOMBASCI_H

#include "commands.h"
#include "SerialPort.h"

namespace sci {
    class RoombaSCI {
    public:
        RoombaSCI(std::string portname, speed_t baud) : serial_(portname, baud) {}

        int connect() { return serial_.connect(); }

        int close() { return serial_.disconnect(); }

        int sendCommand(std::string command, const byteVector &data) {
            if(serial_.getStatus() < 0) {
                std::cerr << "Roomba SCI error: device not connected" << std::endl;
                return -1;
            }

            auto it = cmds_.getCommand(command);

            if (it == cmds_.getEnd()) {
                std::cerr << "Roomba SCI error: command '" << command << "' not found" << std::endl;
                return -1;
            }

            // all commands must start with opcode start, except start itself
            byteVector sequence;
            if (it->first.compare("Start")) {
                sequence.push_back(128);
            }

            sequence.push_back(it->second);
            for (const auto byte : data) {
                sequence.push_back(byte);
            }

            if (serial_.writeVector(sequence) < 0) {
                return -1;
            }

            return 1;
        }

        int readSensors(byteVector &dest) {
            serial_.readAll(dest, 255);
            return 1;
        }

    private:
        Commands cmds_;
        SerialPort serial_;
    };
}

#endif //ROOMBACONTROLLER_ROOMBASCI_H
