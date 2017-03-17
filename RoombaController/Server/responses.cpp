//
// Created by jamie on 3/17/17.
//

#include <fstream>

#include "responses.h"

using namespace std;

void responses::info(shrpResponse response, shrpRequest request) {
    stringstream content_stream;
    content_stream << "<h1>Request from " << request->remote_endpoint_address.c_str() << " (" << request->remote_endpoint_port << ")</h1>";
    content_stream << request->method << " " << request->path << " HTTP/" << request->http_version << "<br>";
    for(auto& header: request->header) {
        content_stream << header.first << ": " << header.second << "<br>";
    }

    //find length of content_stream (length received using content_stream.tellp())
    content_stream.seekp(0, ios::end);

    *response << response200
              << "Content-Length: " << content_stream.tellp() << endh
              << content_stream.rdbuf();
}

