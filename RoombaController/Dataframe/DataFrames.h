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




class Cmd{
private:

public:

    int cmd_Start();
    int cmd_Baud(int Baud);
    int cmd_Control();
    int cmd_Safe();
    int cmd_Full();
    int cmd_Power();
    int cmd_Spot();
    int cmd_Clean();
    int cmd_Max();
    int cmd_Drive(int Vel, int Rad);
    int cmd_Motors(uint8_t Bits);
    int cmd_Leds(uint8_t Bits, int Color, int intensity);
    int cmd_Song();
    int cmd_Play(uint8_t Number);
    int cmd_Sensors(uint8_t Code);
    int cmd_Dock();
};


#endif //DATAFRAMES_DATAFRAMES_H
