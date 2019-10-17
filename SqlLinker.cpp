#include "SqlLinker.h"



SqlLinker::SqlLinker() {
    mysql_init(&this->data);
    if(mysql_real_connect(&this->data,"localhost","root","admin",NULL,3306,NULL,0))    //链接数据库
    {
        cout<<"Succeed!"<<endl;
    }
    else
    {
        cout<<"Error:"<<mysql_error(&this->data)<<endl;
        exit(0);
    }
    if(mysql_query(&this->data,"CREATE DATABASE IF NOT EXISTS student"))     //创建 student库
    {
        cout<<"Error:"<<mysql_error(&this->data)<<endl;
        exit(0);
    }
    mysql_query(&this->data,"USE student");
    if(mysql_query(&this->data,"CREATE TABLE IF NOT EXISTS inf("
                         "id int auto_increment primary key,"
                         "passwd VARCHAR(25) NOT NULL,"
                         "name VARCHAR(25) NOT NULL,"
                         "class int NOT NULL,"
                         "sex char(1) NOT NULL,"
                         "birthday date NOT NULL,"
                         "address VARCHAR(25) NOT NULL,"
                         "car VARCHAR(200) NOT NULL)"))      //创建inf表
    {
        cout<<"Error:"<<mysql_error(&this->data)<<endl;
        exit(0);
    }
    this->Create="INSERT INTO inf(name,id,class,birthday,address,sex,passwd,car)VALUES";
    //初始化SQL拼接字符串
}

SqlLinker::~SqlLinker()
{
    mysql_close(&this->data);     //关闭链接
}

bool SqlLinker::CreateNewStudent(const char *name, int id, int Class, const char* birthday, const char *address, char sex, const char* passwd,const char* car)
{

        string insert=this->Create+"('"+name+"',"+to_string(id)+","+to_string(Class)+",'"+birthday+"','"+address+"','"+sex+"','"+passwd+"','"+car+"')";
        const char *p=(char*)insert.data();
        if(mysql_query(&this->data,p)){
            cout<<"Error :"<<mysql_error(&this->data)<<endl;
            return 0;
        }
         //创建表项
        return 1;
}

string SqlLinker::SearchStudent(int id) {       //返回该学生类的序列号字符串
    MYSQL_RES *result;
    MYSQL_ROW row;
    string insert = "SELECT car FROM inf WHERE id = " + to_string(id);
    const char *p = insert.data();
    if(mysql_query(&this->data, p)==0)
    {
        result=mysql_store_result(&this->data);
        row=mysql_fetch_row(result);
        string tmp=row[0];
        mysql_free_result(result);
        return tmp;
    }
    return "NULL";
}

int SqlLinker::Display(int Class) {     //遍历某班全部学生
    MYSQL_RES *result;
    MYSQL_ROW row;
    string select = "SELECT car FROM inf WHERE class = ";
    const char *p=(select+to_string(Class)).data();
    if(mysql_query(&this->data,p)){
        cout<<"Error:"<<mysql_error(&this->data)<<endl;
        return 0;
    }
    result=mysql_store_result(&this->data);
    int len=mysql_num_fields(result);
    talk.SendMassage();
    while ((row=mysql_fetch_row(result)))
    {
        for (int i = 0;i < len ; i++){
            this->talk.SendMassage(row[i]);
        }
    }
    return 1;
}

bool SqlLinker::Login(int id,const char* password) {   //验证密码是否与ID匹配
    MYSQL_RES *result;
    MYSQL_ROW row;
    string insert = "SELECT passwd FROM inf WHERE id = " + to_string(id);
    const char *p=insert.data();
    mysql_query(&this->data,p);
    result=mysql_store_result(&this->data);
    row=mysql_fetch_row(result);
    string a=row[0];
    string b=password;
    return a == b;
}

bool SqlLinker::IfExist(int id) { //判断相应ID是否存在
    MYSQL_RES *result;
    MYSQL_ROW row;
    string insert = "SELECT id FROM inf WHERE id = " + to_string(id);
    const char *p=insert.data();
    mysql_query(&this->data,p);
    result=mysql_store_result(&this->data);
    row=mysql_fetch_row(result);
    return row != nullptr;
}

