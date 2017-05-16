//
// Created by jamie on 3/17/17.
//

#include <Poco/Logger.h>

#include "responses.h"
#include "glb_session.h"
#include "glb_roomba_param.h"
#include "glb_server_context.h"

using namespace std;
using namespace restbed;

using json = nlohmann::json;

void responses::index(pSession session) {
    const auto request = session->get_request();
    int content_length = request->get_header("Content-Length", 0);
    auto &logger = Poco::Logger::get("logger");

    logger.debug(request->get_method() + " " + request->get_path() + "HTTP/1.1");

    FileHandler page("../web/index.html");
    session->fetch(static_cast<const size_t >(content_length),
                   [&page](const shared_ptr<Session> s, const Bytes &body) {
                       s->close(OK,
                                page.getcontent(),
                                {{"Content-Length", std::to_string(page.getcontent().size())}});
                   });
}

void responses::manual(pSession session) {
    const auto request = session->get_request();
    int content_length = request->get_header("Content-Length", 0);
    auto &logger = Poco::Logger::get("logger");

    logger.debug(request->get_method() + " " + request->get_path() + " HTTP/1.1");

    FileHandler page("../web/control.html");
    session->fetch(static_cast<const size_t >(content_length),
                   [&page](const shared_ptr<Session> s, const Bytes &body) {
                       s->close(OK,
                                page.getcontent(),
                                {{"Content-Length", std::to_string(page.getcontent().size())}});
                   });
}

void responses::autonomous(pSession session) {
    const auto request = session->get_request();
    int content_length = request->get_header("Content-Length", 0);
    auto &logger = Poco::Logger::get("logger");

    logger.debug(request->get_method() + " " + request->get_path() + " HTTP/1.1");

    FileHandler page("../web/Autonomous_mode.html");
    session->fetch(static_cast<const size_t >(content_length),
                   [&page](const shared_ptr<Session> s, const Bytes &body) {
                       s->close(OK,
                                page.getcontent(),
                                {{"Content-Length", std::to_string(page.getcontent().size())}});
                   });
}

void responses::about(pSession session) {
    const auto request = session->get_request();
    int content_length = request->get_header("Content-Length", 0);
    auto &logger = Poco::Logger::get("logger");

    logger.debug(request->get_method() + " " + request->get_path() + " HTTP/1.1");

    FileHandler page("../web/About.html");
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
                       bool exitFlag{};
                       json postData = json::parse(string(body.begin(), body.end()));
                       json_response response;

                       // set session
                       if (postData["session"] == nullptr) {
                           response.error("can't determine source pc or web");
                       } else {
                           if (postData["session"].is_string() && globals::session_id == "") {
                               globals::session_id = postData["session"];
                           } else {
                               response.error("session set error");
                           }
                       }

                       // check if user wants to quit
                       if (postData["exit"] == "true") {
                           if(globals::roomba_session != globals::AUTO) {
                               globals::server_context = globals::ServerContext::E_EXIT;
                               response.ok();
                               exitFlag = true;
                               globals::session_id = "";
                           } else {
                               response.error("busy");
                           }
                       } else if (globals::roomba_session == globals::IDLE) {
                           unique_lock<std::mutex> lk(globals::mut_roomba_session);
                           globals::roomba_session = globals::PC_WEB;
                           globals::cv_roomba_session.notify_one();
                       }

                       // control roomba if session is ok
                       if (globals::roomba_session == globals::PC_WEB && globals::session_id == postData["session"]) {
                           unique_lock<std::mutex> param_lk(globals::rmbPrm.mutex());
                           unique_lock<std::mutex> event_lk(globals::server_context.mutex());

                           // parse direction and speed
                           if (postData["direction"] != nullptr) {
                               if (postData["direction"].is_string()) {
                                   auto direc = postData["direction"];

                                   if (direc == "left") {
                                       globals::server_context = globals::ServerContext::E_LEFT;
                                       response.ok();
                                   } else if (direc == "forward") {
                                       globals::server_context = globals::ServerContext::E_FORWARD;
                                       response.ok();
                                   } else if (direc == "forward-left") {
                                       globals::server_context = globals::ServerContext::E_FORWARD_LEFT;
                                       response.ok();
                                   } else if (direc == "right") {
                                       globals::server_context = globals::ServerContext::E_RIGHT;
                                       response.ok();
                                   } else if (direc == "forward-right") {
                                       globals::server_context = globals::ServerContext::E_FORWARD_RIGHT;
                                       response.ok();
                                   } else if (direc == "backward") {
                                       globals::server_context = globals::ServerContext::E_BACKWARD;
                                       response.ok();
                                   } else if (direc == "backward-left") {
                                       globals::server_context = globals::ServerContext::E_BACKWARD_LEFT;
                                       response.ok();
                                   } else if (direc == "backward-right") {
                                       globals::server_context = globals::ServerContext::E_BACKWARD_RIGHT;
                                       response.ok();
                                   } else if (direc == "stop") {
                                       globals::server_context = globals::ServerContext::E_STOP;
                                       response.ok();
                                   } else {
                                       response.error("unsupported direction");
                                   }
                               } else {
                                   response.error("direction must be a string");
                               }

                               if (postData["wheel_speed"] != nullptr) {
                                   if (postData["wheel_speed"].is_number()) {
                                       globals::server_context.setWheelSpeed(
                                               static_cast<double>(postData["wheel_speed"]));
                                   } else {
                                       response.error("wheel speed must be a number");
                                   }
                               } else {
                                   globals::server_context.setWheelSpeed(1.0);
                               }
                           }

                           // parse brush
                           if (postData["brush_speed"] != nullptr) {
                               if (postData["brush_speed"].is_number()) {
                                   globals::server_context.setBrushSpeed(static_cast<unsigned int>(postData["brush_speed"]));
                               } else {
                                   response.error("brush must be a number");
                               }
                           } else {
                               globals::server_context.setBrushSpeed(0);
                           }

                           // parse pre commands
                           if (postData["pre-commands"] != nullptr) {
                               if (postData["pre-commands"].is_string()) {
                                   auto cmd = postData["pre-commands"];

                                   if (cmd == "clean") {
                                       globals::server_context = globals::ServerContext::E_CLEAN;
                                   } else if (cmd == "dock") {
                                       globals::server_context = globals::ServerContext::E_DOCK;
                                   } else if (cmd == "spot") {
                                       globals::server_context = globals::ServerContext::E_SPOT;
                                   } else {
                                       response.error("unsupported command");
                                   }
                               } else {
                                   response.error("command must be a string");
                               }
                           }
                       } else {
                           if (exitFlag) response.ok("closing session");
                           else response.error("busy");
                       }

                       // send response variables
                       s->close(OK,
                                response.to_string(),
                                {{"Content-Length", std::to_string(response.size())}});
                   });
}

void responses::status(pSession session) {
    const auto request = session->get_request();
    int content_length = request->get_header("Content-Length", 0);
    auto &logger = Poco::Logger::get("logger");

    //logger.debug(request->get_method() + " " + request->get_path() + " HTTP/1.1 ");

    session->fetch(static_cast<const size_t >(content_length),
                   [](const shared_ptr<Session> s, const Bytes &body) {
                       json response;

                       if(globals::roomba_session == globals::IDLE) response["status"] = "available";
                       else response["status"] = "running";

                       auto sensorData = globals::server_context.getSensorData();
                       response["battery"] = sensorData.getvalue<unsigned short>(Battery_capacity);

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


void responses::json_response::ok(std::string message) {
    response_["status"] = "ok";
    response_["message"] = message;
}

void responses::json_response::error(std::string message) {
    response_["status"] = "error";
    response_["message"] = message;
}

std::string responses::json_response::to_string() const {
    return response_.dump();
}

unsigned long responses::json_response::size() const {
    return response_.dump().size();
}
