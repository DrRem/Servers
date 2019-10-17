
#ifndef SERVERS_SQLLINKER_H
#define SERVERS_SQLLINKER_H

#include "Socks.h"
#include "mysql.h"
#include "iostream"
#include "windows.h"
#include "unistd.h"
using namespace std;

class SqlLinker{
protected:
    string Create;
    MYSQL data;     //连接器
public:
    Socks talk;       //初始化Socket
    SqlLinker();
    ~SqlLinker();

    bool CreateNewStudent(const char* name,int id,int Class,const char* birthday,const char* address,char sex,const char* passwd, const char* car);  //添加新成员
    string SearchStudent(int id);
    int Display(int Class);
    bool Login(int id,const char* password);
    bool IfExist(int id);
};


#endif
