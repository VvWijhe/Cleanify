//
// Created by jamie on 3/17/17.
//

#include "responses.h"
#include "../json.hpp"
#include "../globals.h"

using namespace std;
using namespace restbed;

using json = nlohmann::json;

const std::vector<std::string> HTML_Commands = {"LF",
                                                "F",
                                                "RF",
                                                "L",
                                                "STOP",
                                                "R",
                                                "LB",
                                                "B",
                                                "RB",
                                                "BRUSH",
                                                "STOP",
                                                "MUSIC",
                                                "CLEAN",
                                                "SPOT",
                                                "DOCK",
                                                "GREEN",
                                                "ORANGE",
                                                "RED",
                                                "BLUE"};

void responses::info(pSession session) {
    const auto request = session->get_request();

    int content_length = request->get_header("Content-Length", 0);
    FileHandler page("../web/index.html");
    session->fetch(static_cast<const size_t >(content_length),
                   [&page](const shared_ptr<Session> s, const Bytes &body) {
                       s->close(OK,
                                page.getcontent(),
                                {{"Content-Length", std::to_string(page.getcontent().size())}});
                   });
}

void responses::request(pSession session) {
    const auto request = session->get_request();

    int content_length = request->get_header("Content-Length", 0);
    session->fetch(static_cast<const size_t >(content_length),
                   [](const shared_ptr<Session> s, const Bytes &body) {
                       json json2 = json::parse(string(body.begin(), body.end()));
                       cout << json2["direction"] << endl;
                       std::string page = "FAILED";
                       for (auto c: HTML_Commands) {
                           if (c == json2["direction"]) {
                               // obtain acces to the roomba session variable
                               unique_lock<std::mutex> lk(globals::mut_roomba_session);
                               globals::roomba_session = globals::WEB;
                               globals::cv_roomba_session.notify_one();

                               page = "succes";
                               break;
                           } else {
                               page = "Command doesn't exist";
                           }
                       }
                       s->close(OK,
                                page,
                                {{"Content-Length", std::to_string(page.size())}});
                   });
}

void responses::error404(pSession session) {
    const auto request = session->get_request();

    int content_length = request->get_header("Content-Length", 0);

    session->fetch(static_cast<const size_t >(content_length),
                   [](const shared_ptr<Session> s, const Bytes &body) {
                       std::string content("Error 404, page not found");

                       s->close(NOT_FOUND,
                                content,
                                {{"Content-Length", std::to_string(content.size())}});
                   });
}


