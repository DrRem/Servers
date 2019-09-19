#include "SqlLinker.h"
#include "Socks.h"
int main() {
    WSADATA data;
    WSAStartup(MAKEWORD(2,2),&data);
    //初始化socket模块
    SqlLinker linker;
    //初始化Sql链接模块
}