#include "serial/SerialPort.h"
#include "Dataframe/DataFrames.h"
#include <iostream>

using namespace std;



int main()
{
    Cmd commands;


    auto it = commands.getCommands().find("Song");

    it -> first;
    it -> second;

    char opcode = it -> second;

    cout << opcode << endl;




    cout << "hello world" << endl;
    return 0;
}