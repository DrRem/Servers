#ifndef SERVERS_SQLLINKER_H
#define SERVERS_SQLLINKER_H

#include "Date.h"
#include "Socks.h"
#include "mysql.h"
#include "iostream"
#include "windows.h"
#include "unistd.h"
using namespace std;

class SqlLinker{
protected:
    string id,name,Class,birthday,address,sex,passwd,Create;
    MYSQL_RES *result;      //接收器
    MYSQL_ROW row;      //结果迭代器
    MYSQL data;     //连接器
public:
    SqlLinker();
    ~SqlLinker();
    int CreateNewStudent(char* name,int id,int Class,Date birthday,char* address,char sex,int passwd);  //添加新成员
};


#endif
