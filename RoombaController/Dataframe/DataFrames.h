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




class Cmd{
private:

    std::map<std::string,unsigned char> Commands;

public:
    Cmd()
    {
        Cmd::Commands["Start"]     = 128;
        Cmd::Commands["Baud"]      = 129;
        Cmd::Commands["Control"]   = 130;
        Cmd::Commands["Safe"]      = 131;
        Cmd::Commands["Full"]      = 132;
        Cmd::Commands["Power"]     = 133;
        Cmd::Commands["Spot"]      = 134;
        Cmd::Commands["Clean"]     = 135;
        Cmd::Commands["Max"]       = 136;
        Cmd::Commands["Drive"]     = 137;
        Cmd::Commands["Motors"]    = 138;
        Cmd::Commands["Leds"]      = 139;
        Cmd::Commands["Song"]      = 140;
        Cmd::Commands["Play"]      = 141;
        Cmd::Commands["Sensors"]   = 142;
        Cmd::Commands["Dock"]      = 143;

    }

    int dataFrames();

    const std::map<std::string, unsigned char> &getCommands() const;


};


#endif //DATAFRAMES_DATAFRAMES_H
