#include <iostream>
#include <thread>
#include <csignal>

#include "Poco/AsyncChannel.h"
#include "Poco/ConsoleChannel.h"
#include "Poco/FileChannel.h"
#include "Poco/FormattingChannel.h"
#include "Poco/Logger.h"
#include "Poco/PatternFormatter.h"
#include "Poco/SplitterChannel.h"

#include "roomba_statemachine.h"

using namespace std;
using namespace systemcontrol;
using namespace Poco;

const string releaseCmd = "rfcomm release " + rfcomm;
const string connectCmd = "rfcomm connect " + rfcomm + " 00:06:66:60:07:81"; //00:06:66:60:07:81

void exitHandler(int signal) {
    system(releaseCmd.c_str());
    exit(1);
}

/**
 * @brief Main entry of the program
 * @return 
 */
int main() {
    try {
//        // set exit handler
//        signal(SIGINT, exitHandler);
//
//        thread t([]{
//            system(connectCmd.c_str());
//        });
//
//        this_thread::sleep_for(chrono::seconds(6));

        //initialise logger
        AutoPtr<SplitterChannel> splitterChannel(new SplitterChannel());

        AutoPtr<Channel> consoleChannel(new ConsoleChannel());
        AutoPtr<Channel> fileChannel(new FileChannel("logfile.log"));
        splitterChannel->addChannel(consoleChannel);
        splitterChannel->addChannel(fileChannel);

        AutoPtr<Channel> formattingChannel(
                new FormattingChannel(new PatternFormatter("%d-%m-%Y %L%H:%M:%S %p: %t"), splitterChannel));
        Logger::create("logger", formattingChannel, Message::PRIO_TRACE);

        // create statemachine
        shared_ptr<RoombaStateContext> process = make_shared<RoombaStateContext>(make_shared<states::Initialise>());

        process->runAll();

//        t.detach();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}
