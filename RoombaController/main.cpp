#include <iostream>
#include "serial/SerialPort.h"
#include "serial/DataFrames.h"

using namespace std;

int main()
{



    SerialPort serial("/dev/", 9600);
    serial.connect();
    serial.swrite({186});
    serial.sread();
    serial.disconnect();



    return 0;
}
