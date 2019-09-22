//
// Created by fffei on 2019/9/17.
//

#ifndef SERVERS_SOCKS_H
#define SERVERS_SOCKS_H

#include "winsock2.h"
#include "iostream"
using namespace std;

class Socks {
protected:
    WSADATA data;
    SOCKET servers;   //socket通信器
    sockaddr_in serverAddress;    //通信端口
    SOCKET client;      //socket客户端
    sockaddr_in clientAdder;       //客户端地址
    int adderLen;
    char buf[MAXBYTE];
public:
    Socks();
    ~Socks();
    int SendMassage(const char* str);
    char* ListenTo();

};


#endif //SERVERS_SOCKS_H
