#ifndef CLIENT_H
#define CLIENT_H
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>


#define PORT 3490
#define MAXSIZE 1024

void client_connect(int argc, char *argv[]);
void client_write(const char buffer[]);
void client_recv();
void client_disconnect();

#endif
