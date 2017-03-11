//
// Created by raymon on 11-3-17.
//

#ifndef FEMALE_REPLACEMENT_SERIALPORT_H
#define FEMALE_REPLACEMENT_SERIALPORT_H

class SerialPort{
private:

public:
    void connect(void);
    void disconnect(void);
    void write(unsigned char cmd[]);
    void read(void);
};

#endif //FEMALE_REPLACEMENT_SERIALPORT_H
