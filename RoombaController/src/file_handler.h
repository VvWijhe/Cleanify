//
// Created by bas on 27-3-17.
//

#ifndef ROOMBACONTROLLER_FILE_HANDLER_H
#define ROOMBACONTROLLER_FILE_HANDLER_H

#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>

class FileHandler{
public:
    FileHandler(const std::string &path) {
        if (open(path) < 0){
            std::cerr << "FileHandler:  can't open file '" << path << "'" << std::endl;
        }
    }

    ~FileHandler() = default;

    int open(const std::string &path){
        std::ifstream website(path);

        if (!website.is_open()){
            return -1;
        }
        else{
            std::stringstream ss;
            ss << website.rdbuf();
            content_ = ss.str();
            return 1;
        }
    }
    std::string getcontent() const {
        return  content_;
    }
private:
    std::string content_;

};



#endif //ROOMBACONTROLLER_FILE_HANDLER_H
