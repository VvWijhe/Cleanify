#include "serial/SerialPort.h"
#include <iostream>

using namespace std;

#include <string>
#include <iostream>
#include <map>
#include <vector>

int main()
{
    std::map<std::string,unsigned char> Commands;
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

    auto it = Commands.find("Start");
    it ->first;
    it ->second;

    auto opcode = it->second;
    vector<unsigned char> dataToSend {opcode};
    /*
    if (it != Commands.end()) std::cout << "Start: " << it->second << "\n";

    it = Commands.find("z");
    if (it != Commands.end()) std::cout << "z1: " << it->second << "\n";

    // Accessing a non-existing element creates it
    if (Commands["z"] == 42) std::cout << "Oha!\n";

    it = Commands.find("z");
    if (it != Commands.end()) std::cout << "z2: " << it->second << "\n";
    */
    return 0;
}