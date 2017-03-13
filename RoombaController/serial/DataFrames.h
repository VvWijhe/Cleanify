//
// Created by victor on 11.03.17.
//

#ifndef DATAFRAMES_DATAFRAMES_H
#define DATAFRAMES_DATAFRAMES_H

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>

class Commands{
public:
    Commands()
    {
        commands_["Start"]     = 128;
        commands_["Baud"]      = 129;
        commands_["Control"]   = 130;
        commands_["Safe"]      = 131;
        commands_["Full"]      = 132;
        commands_["Power"]     = 133;
        commands_["Spot"]      = 134;
        commands_["Clean"]     = 135;
        commands_["Max"]       = 136;
        commands_["Drive"]     = 137;
        commands_["Motors"]    = 138;
        commands_["Leds"]      = 139;
        commands_["Song"]      = 140;
        commands_["Play"]      = 141;
        commands_["Sensors"]   = 142;
        commands_["Dock"]      = 143;

    }

    std::map<std::string, unsigned char> getCommands() const {
        return commands_;
    }

    std::map<std::string, unsigned char>::iterator getOpcode(std::string opcode) const{

        auto it = getCommands().find(opcode);

        return it;
    };

private:
    std::map<std::string,unsigned char> commands_;
};


#endif //DATAFRAMES_DATAFRAMES_H
