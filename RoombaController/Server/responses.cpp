//
// Created by jamie on 3/17/17.
//

#include <fstream>

#include "responses.h"

using namespace std;
using namespace restbed;

void responses::info(pSession session) {
    const auto request = session->get_request();

    int content_length = request->get_header("Content-Length", 0);

    session->fetch(content_length,
                   [](const shared_ptr<Session> s, const Bytes &body) {
                       s->close(OK,
                                "Hello, World!",
                                {{"Content-Length", "13"}});
                   });
}

void responses::error404(pSession session) {
    const auto request = session->get_request();

    int content_length = request->get_header("Content-Length", 0);

    session->fetch(content_length,
                   [](const shared_ptr<Session> s, const Bytes &body) {
                       std::string content("Error 404, page not found");

                       s->close(NOT_FOUND,
                                content,
                                {{"Content-Length", std::to_string(content.size())}});
                   });
}
