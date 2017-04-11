//
// Created by jamie on 3/15/17.
//

#include <iostream>
#include "server.h"

using namespace server;
using namespace std;
using namespace restbed;

RoombaServer::RoombaServer(unsigned short port) {
    settings_ = make_shared<Settings>();
    settings_->set_port(port);
    settings_->set_default_header("Connection", "close");

    // main page reponse
    auto resource = make_shared<Resource>();
    resource->set_path("/");
    resource->set_method_handler("GET", responses::info);
    service_.publish(resource);

    auto resource1 = make_shared<Resource>();
    resource1->set_path("/ajax_info");
    resource1->set_method_handler("POST", responses::ajax);
    service_.publish(resource1);

    // 404 page not found
    service_.set_not_found_handler(responses::error404);
}

RoombaServer::~RoombaServer() {

}

void RoombaServer::run() {
    thread_ = thread([this]() {
        this->service_.start(settings_);
    });

    this_thread::sleep_for(chrono::seconds(1));

    cout << "server started" << endl;
}

void RoombaServer::stop() {
    service_.stop();
    thread_.join();
    cout << "server stopped" << endl;
}
