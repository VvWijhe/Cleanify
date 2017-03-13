#include <iostream>
#include "serial/SerialPort.h"
#include "Dataframe/DataFrames.h"

using namespace std;

int main()
{
    Cmd commands;


    auto it = commands.getCommands().find("Song");

    it -> first;
    it -> second;

    char opcode = it -> second;

    vector <unsigned  char> dataToSend;




    cout << opcode << endl;

    cout << "hello world" << endl;



    //testing::InitGoogleTest(&argc, argv);
    //RUN_ALL_TESTS();
    return 0;
}
