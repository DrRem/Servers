
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
    string id,name,Class,birthday,address,sex,passwd,Create;
    MYSQL data;     //连接器
public:
    SqlLinker();
    ~SqlLinker();
    int CreateNewStudent(const char* name,int id,int Class,const char* birthday,const char* address,char sex,int passwd);  //添加新成员
};


#endif
