//
// Created by fffei on 2019/9/17.
//

#include <inaddr.h>
#include "Socks.h"

Socks::Socks() {
    this->adderLen=sizeof(SOCKADDR);
    this->TCPLinker=socket(AF_INET,SOCK_STREAM,0);      //初始为TCP协议
    memset(&this->Address,0, sizeof(this->Address));    //初始化地址
    this->Address.sin_family=PF_INET;   //设置地址类型为IPV4
    this->Address.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");      //绑定地址
    this->Address.sin_port=htons(9999);     //绑定端口
    bind(this->TCPLinker,(SOCKADDR*)&this->Address,this->adderLen);       //绑定
}

Socks::~Socks() {
    closesocket(this->TCPLinker);
}

int Socks::SendMassage(const char *str) {
    listen(this->TCPLinker,20);
    SOCKET client;      //socket客户端
    SOCKADDR clientAdder;       //客户端地址

    return 0;
}
