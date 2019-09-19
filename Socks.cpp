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
    this->Address.sin_port=htons(8848);     //绑定端口
    bind(this->TCPLinker,(SOCKADDR*)&this->Address,this->adderLen);       //绑定
    listen(this->TCPLinker,20);//开始侦听
    cout<<"waiting for connect..."<<endl;
    this->client=accept(TCPLinker,(SOCKADDR*)&clientAdder,&adderLen);  //连接到客户端
    cout<<"connect:"<<this->clientAdder.sa_data<<endl;
}

Socks::~Socks() {
    closesocket(this->TCPLinker);
    closesocket(this->client);
    cout<<"Socket Exit!"<<endl;
}

int Socks::SendMassage(const char *str) {
    send(this->client,str,strlen(str)* sizeof(char),NULL);
    return 0;
}

