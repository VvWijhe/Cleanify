//
// Created by jamie on 3/17/17.
//

#include <Poco/Logger.h>

#include "responses.h"
#include "json.hpp"
#include "glb_session.h"
#include "glb_roomba_param.h"
#include "glb_events.h"

using namespace std;
using namespace restbed;

using json = nlohmann::json;

void responses::index(pSession session) {
    const auto request = session->get_request();
    int content_length = request->get_header("Content-Length", 0);
    auto &logger = Poco::Logger::get("logger");

    logger.debug(request->get_method() + " " + request->get_path() + " HTTP/1.1");

    FileHandler page("../web/index.html");
    session->fetch(static_cast<const size_t >(content_length),
                   [&page](const shared_ptr<Session> s, const Bytes &body) {
                       s->close(OK,
                                page.getcontent(),
                                {{"Content-Length", std::to_string(page.getcontent().size())}});
                   });
}

void responses::handle_post(pSession session) {
    const auto request = session->get_request();
    int content_length = request->get_header("Content-Length", 0);
    auto &logger = Poco::Logger::get("logger");

    logger.debug(request->get_method() + " " + request->get_path() + " HTTP/1.1 ");

    session->fetch(static_cast<const size_t >(content_length),
                   [](const shared_ptr<Session> s, const Bytes &body) {
                       json response,
                               postData = json::parse(string(body.begin(), body.end()));

                       // set session
                       if (postData["Session"] == nullptr) {
                           response["Message"].push_back("Can't determine source PC or webapp");
                       } else {
                           if (postData["Session"].is_string()) {
                               globals::session_id = postData["Session"];
                           } else {
                               response["Message"].push_back("Session type must be a string");
                           }
                       }

                       // check if user wants to quit
                       if(postData["Exit"] == "true") {
                           globals::server_event = globals::ServerEvents::E_EXIT;
                           response["Message"].push_back("Session closed");
                       } else if(globals::roomba_session == globals::IDLE) {
                           unique_lock<std::mutex> lk(globals::mut_roomba_session);
                           globals::roomba_session = globals::SESSION;
                           globals::cv_roomba_session.notify_one();
                       }

                       // set global variables if session is ok
                       if (globals::roomba_session == globals::SESSION && globals::session_id == postData["Session"]) {
                           unique_lock<std::mutex> param_lk(globals::rmbPrm.mutex());
                           unique_lock<std::mutex> event_lk(globals::server_event.mutex());

                           // parse direction
                           if (postData["Direction"] != nullptr) {
                               if (postData["Direction"].is_string()) {
                                   auto data = postData["Direction"];

                                   if (data == "Left") {
                                       globals::server_event = globals::ServerEvents::E_LEFT;
                                       response["Message"].push_back("Succes");
                                   } else if (data == "Forward") {
                                       globals::server_event = globals::ServerEvents::E_FORWARD;
                                       response["Message"].push_back("Succes");
                                   } else if (data == "Right") {
                                       globals::server_event = globals::ServerEvents::E_RIGHT;
                                       response["Message"].push_back("Succes");
                                   } else if (data == "Backward") {
                                       globals::server_event = globals::ServerEvents::E_BACKWARD;
                                       response["Message"].push_back("Succes");
                                   } else if (data == "Stop") {
                                       globals::server_event = globals::ServerEvents::E_STOP;
                                       response["Message"].push_back("Succes");
                                   } else {
                                       response["Message"].push_back("Unsupported direction");
                                   }
                               } else {
                                   response["Message"].push_back("Direction must be a string");
                               }
                           }
                       } else {
                           response["Message"].push_back("Busy");
                       }

                       // send response variables
                       s->close(OK,
                                response.dump(),
                                {{"Content-Length", std::to_string(response.dump().size())}});
                   });
}

void responses::status(pSession session) {
    const auto request = session->get_request();
    int content_length = request->get_header("Content-Length", 0);
    auto &logger = Poco::Logger::get("logger");

    logger.debug(request->get_method() + " " + request->get_path() + " HTTP/1.1 ");

    session->fetch(static_cast<const size_t >(content_length),
                   [](const shared_ptr<Session> s, const Bytes &body) {
                       json response;

                       response["Status"] = "Idle";
                       response["Battery"] = 71;

                       s->close(OK,
                                response.dump(),
                                {{"Content-Length", std::to_string(response.dump().size())}});
                   });
}

void responses::error404(pSession session) {
    const auto request = session->get_request();
    int content_length = request->get_header("Content-Length", 0);
    auto &logger = Poco::Logger::get("logger");

    logger.debug(request->get_method() + " " + request->get_path() + " HTTP/1.1 ");

    session->fetch(static_cast<const size_t >(content_length),
                   [](const shared_ptr<Session> s, const Bytes &body) {
                       std::string content("Error 404, page not found");

                       s->close(NOT_FOUND,
                                content,
                                {{"Content-Length", std::to_string(content.size())}});
                   });
}


