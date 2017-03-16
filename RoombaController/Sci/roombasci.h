//
// Created by victor on 13.03.17.
//

#ifndef ROOMBACONTROLLER_ROOMBASCI_H
#define ROOMBACONTROLLER_ROOMBASCI_H

#include "DataFrames.h"
#include "SerialPort.h"

//for commit


namespace roombaSCI {

    class RoombaSCI {
    public:
        RoombaSCI(std::string portname, speed_t baud) : serial_(portname, baud) {}

        

        int sendCommand(std::string command, const byteVector &data) {
            auto it = cmds_.getCommand(command);

            if (it == cmds_.getEnd()) {
                std::cerr << "error: command not found" << std::endl;
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

            if (serial_.swrite(sequence) < 0) {
                return -1;
            }

            return 1;
        }

    private:

        byteVector data_;

        Commands cmds_;
        SerialPort serial_;
    };
}

#endif //ROOMBACONTROLLER_ROOMBASCI_H
