#include <inaddr.h>
#include "Socks.h"

Socks::Socks() {
    if(WSAStartup(MAKEWORD(2,2),&data)!=0){
        cout<<"WSA Error!"<<endl;
    }
    this->adderLen=sizeof(sockaddr);
    this->servers=socket(AF_INET,SOCK_STREAM,0);      //初始为TCP协议
    if(this->servers==INVALID_SOCKET){
        cout<<"socket Error"<<endl;
    }
    memset(&this->serverAddress,0, sizeof(this->serverAddress));    //初始化地址
    this->serverAddress.sin_family=PF_INET;   //IPV4
    this->serverAddress.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");      //地址
    this->serverAddress.sin_port=htons(8848);     //端口
    //绑定
    if(bind(this->servers,(const struct sockaddr*)&this->serverAddress,sizeof(this->serverAddress))==SOCKET_ERROR){
        cout<<"bind Error!"<<endl;
    }
    //listen(this->servers,5);//开始侦听
    if(listen(this->servers,5)==SOCKET_ERROR){
        cout<<"listen Error!"<<endl;
    }
    cout<<"waiting for connect..."<<endl;
    this->client=accept(this->servers,(SOCKADDR*)&this->clientAdder,&this->adderLen);  //连接到客户端
    if(this->client==INVALID_SOCKET){
        cout<<"client connect Error!"<<endl;
    }
    cout<<"connect:"<<this->clientAdder.sin_port<<endl;
}

Socks::~Socks() {
    closesocket(this->servers);
    closesocket(this->client);
    WSACleanup();
    cout<<"\nSocket Exit!"<<endl;
}

int Socks::SendMassage(const char *str) {
    send(this->client,str,strlen(str)* sizeof(char),0);      //发送数据
    return 0;
}

char* Socks::ListenTo() {
    ZeroMemory(buf,MAXBYTE);        //清空buf
    if(recv(this->client,this->buf,MAXBYTE,0)==SOCKET_ERROR){
        cout<<"recv Error!"<<endl;
    }         //接收数据
    return this->buf;
}

