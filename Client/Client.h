#pragma once
#include <iostream>
#include <string.h>

#if defined (_WIN32) || (_WIN64)
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#elif defined (__linux__)
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#endif

using namespace std;

#define MESSAGE_LENGTH 1024
#define PORT 7777

class Client
{
public:
#if defined (_WIN32) || (_WIN64)
    WSADATA wsaData;
    SOCKET socket_file_descriptor, connection;
#elif defined (__linux__)
    int socket_file_descriptor, connection;
#endif
    struct sockaddr_in serveraddress, client;

    void createSocket();
    void connectionToServer();
    void closeSocket();
    char* readData();
    void writeData(string clientMessage);

private:
    char message[MESSAGE_LENGTH];
};