//
// Created by fffei on 2019/9/15.
//
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
    if(mysql_query(&this->data,"CREATE DATABASE IF NOT EXISTS student;"))     //创建 student库
    {
        cout<<"Error:"<<mysql_error(&this->data)<<endl;
        exit(0);
    }
    mysql_query(&this->data,"USE student");
    if(mysql_query(&this->data,"CREATE TABLE IF NOT EXISTS inf("
                         "id int auto_increment primary key,"
                         "passwd int NOT NULL,"
                         "name VARCHAR(25) NOT NULL,"
                         "class int NOT NULL,"
                         "sex char(1) NOT NULL,"
                         "birthday date,"
                         "address VARCHAR(25));"))      //创建inf表
    {
        cout<<"Error:"<<mysql_error(&this->data)<<endl;
        exit(0);
    }
    this->id="SELECT * FROM inf WHERE id";
    this->passwd="SELECT * FROM inf WHERE passwd";
    this->name="SELECT * FROM inf WHERE name";
    this->Class="SELECT * FROM inf WHERE class";
    this->sex="SELECT * FROM inf WHERE sex";
    this->birthday="SELECT * FROM inf WHERE birthday";
    this->address="SELECT * FROM inf WHERE address";
    this->Create="INSERT INTO inf(name,id,class,birthday,address,sex,passwd)VALUES";
    //初始化SQL拼接字符串
}

SqlLinker::~SqlLinker()
{
    mysql_close(&this->data);     //关闭链接
}

int SqlLinker::CreateNewStudent(const char *name, int id, int Class, const char* birthday, const char *address, char sex, int passwd)
{

        string insert=this->Create+"('"+name+"',"+to_string(id)+","+to_string(Class)+",'"+birthday+"','"+address+"','"+sex+"',"+to_string(passwd)+");";
        const char *p=(char*)insert.data();
        if(mysql_query(&this->data,p)){
            cout<<"Error :"<<mysql_error(&this->data)<<endl;
        }
         //创建表项
        return 1;
}
