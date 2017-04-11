#include <iostream>
#include "Subsystems/devices.h"
#include "Server/server.h"

using namespace std;

int main() {
    server::RoombaServer s(8000);
    try {
        s.run();
        cin.ignore();
    }
    catch(exception &e){
        cout << e.what() << endl;
    }

    return 0;
}
