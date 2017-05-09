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

    // main page response
    auto resource = make_shared<Resource>();
    resource->set_path("/");
    resource->set_method_handler("GET", responses::index);
    service_.publish(resource);

    // manual page response
    auto resource1 = make_shared<Resource>();
    resource1->set_path("/manual");
    resource1->set_method_handler("GET", responses::manual);
    service_.publish(resource1);

    //autonomous page response
    auto resource2 = make_shared<Resource>();
    resource2->set_path("/autonomous");
    resource2->set_method_handler("GET", responses::autonomous);
    service_.publish(resource2);



    //about page response
    auto resource7 = make_shared<Resource>();
    resource7->set_path("/about");
    resource7->set_method_handler("GET", responses::about);
    service_.publish(resource7);

    // post instruction
    auto resource8 = make_shared<Resource>();
    resource8->set_path("/control");
    resource8->set_method_handler("POST", responses::handle_post);
    service_.publish(resource8);

    auto resource9 = make_shared<Resource>();
    resource9->set_path("/status");
    resource9->set_method_handler("GET", responses::status);
    service_.publish(resource9);

    // 404 page not found
    service_.set_not_found_handler(responses::error404);
}

RoombaServer::~RoombaServer() {
    stop();
}

void RoombaServer::run() {
    thread_ = thread([this]() {
        this->service_.start(settings_);
    });

    this_thread::sleep_for(chrono::milliseconds(300));

    isStarted = true;
}

void RoombaServer::stop() {
    if(!isStarted) return;
    service_.stop();
    thread_.join();
    isStarted = false;
    cout << "server stopped" << endl;
}

bool RoombaServer::started() const {
    return isStarted;
}
