//
// Created by jamie on 3/17/17.
//

#include "responses.h"
#include "../json.hpp"
#include <iostream>

using namespace std;
using namespace restbed;

using json = nlohmann::json;

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

void responses::ajax(pSession session) {
    const auto request = session->get_request();

    int content_length = request->get_header("Conten                       cout << j << endl;t-Length", 0);
    session->fetch(static_cast<const size_t >(content_length),
                   [](const shared_ptr<Session> s, const Bytes &body) {
                       json json2 = json::parse( string(body.begin(), body.end()) );
                       cout << json2["direction"] << endl;
                       std::string page = "succes";
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
