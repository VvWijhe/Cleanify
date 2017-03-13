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
        Commands["Start"]     = 128;
        Commands["Baud"]      = 129;
        Commands["Control"]   = 130;
        Commands["Safe"]      = 131;
        Commands["Full"]      = 132;
        Commands["Power"]     = 133;
        Commands["Spot"]      = 134;
        Commands["Clean"]     = 135;
        Commands["Max"]       = 136;
        Commands["Drive"]     = 137;
        Commands["Motors"]    = 138;
        Commands["Leds"]      = 139;
        Commands["Song"]      = 140;
        Commands["Play"]      = 141;
        Commands["Sensors"]   = 142;
        Commands["Dock"]      = 143;

    }

    int dataFrames();

    const std::map<std::string, unsigned char> &getCommands() const;

    std::vector<unsigned char> fillVector();

};


#endif //DATAFRAMES_DATAFRAMES_H
