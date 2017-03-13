//
// Created by victor on 13.03.17.
//

#ifndef ROOMBACONTROLLER_ROOMBASCI_H
#define ROOMBACONTROLLER_ROOMBASCI_H

#include "DataFrames.h"
#include "SerialPort.h"


namespace roombaSCI {

    class RoombaSCI {
    public:
        RoombaSCI(std::string portname, speed_t baud) : serial_(portname, baud) {}

        int sendCommand(std::string command, const byteVector &data) {
            auto it = cmds_.getOpcode(command);

            if (it == std::end(it)) {
                return -1;
            }

            byteVector sequence = {it->second};

            for (const auto byte : data) {
                sequence.push_back(byte);
            }

            if (serial_.swrite(sequence) < 0) {
                return -1;
            }

            return 1;
        }

    private:
        Commands cmds_;
        SerialPort serial_;
    };
}

#endif //ROOMBACONTROLLER_ROOMBASCI_H
