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

class Commands {
public:
    Commands() {
        commands_["Start"] = 128;
        commands_["Baud"] = 129;
        commands_["Control"] = 130;
        commands_["Safe"] = 131;
        commands_["Full"] = 132;
        commands_["Power"] = 133;
        commands_["Spot"] = 134;
        commands_["Clean"] = 135;
        commands_["Max"] = 136;
        commands_["Drive"] = 137;
        commands_["Motors"] = 138;
        commands_["Leds"] = 139;
        commands_["Song"] = 140;
        commands_["Play"] = 141;
        commands_["Query"] = 142;
        commands_["Dock"] = 143;
        commands_["PwmMotors"] = 144;
        commands_["DriveWheels"] = 145;
        commands_["DrivePwm"] = 146;
        commands_["Stream"] = 148;
        commands_["QueryList"] = 149;
        commands_["DoStream"] = 150;
        commands_["SchedulingLeds"] = 162;
        commands_["LedsRaw"] = 163;
        commands_["LedsAscii"] = 164;
        commands_["Buttons"] = 165;
        commands_["Schedule"] = 167;
        commands_["SetDay"] = 168;
        commands_["Stop"] = 173;
    }

    std::map<std::string, unsigned char> getMap() const {
        return commands_;
    }

    std::map<std::string, unsigned char>::const_iterator getCommand(std::string cmd) const {
        return commands_.find(cmd);
    };

    std::map<std::string, unsigned char>::iterator getEnd() {
        return commands_.end();
    }

private:
    std::map<std::string, unsigned char> commands_;
};


#endif //DATAFRAMES_DATAFRAMES_H
