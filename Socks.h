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
    SOCKET TCPLinker;   //socket通信器
    sockaddr_in Address;    //通信端口
    SOCKET client;      //socket客户端
    SOCKADDR clientAdder;       //客户端地址
    int adderLen;
public:
    Socks();
    ~Socks();
    int SendMassage(const char* str);

};


#endif //SERVERS_SOCKS_H
