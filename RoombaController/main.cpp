#include <iostream>
#include "io/roombasci.h"
#include "Server/server.h"

using namespace std;

int main() {
    server::RoombaServer roombaServer(8080);
    roombaServer.run();
    cin.ignore();
    roombaServer.stop();

    return 0;
}
