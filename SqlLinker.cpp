//
// Created by fffei on 2019/9/15.
//
#include "SqlLinker.h"



SqlLinker::SqlLinker() {
    MYSQL data;
    mysql_init(&data);
    if(mysql_real_connect(&data,"localhost","root","toor",NULL,3306,NULL,0))    //链接数据库
    {
        cout<<"Succeed!"<<endl;
    }
    else
    {
        cout<<"Error:"<<mysql_error(&data)<<endl;
        exit(0);
    }
    if(mysql_query(&data,"CREATE DATABASE IF NOT EXISTS student;"))     //创建 student库
    {
        cout<<"Error:"<<mysql_error(&data)<<endl;
        exit(0);
    }
    mysql_query(&data,"USE student");
    if(mysql_query(&data,"CREATE TABLE IF NOT EXISTS inf("
                         "id int auto_increment primary key,"
                         "passwd int NOT NULL,"
                         "name VARCHAR(25) NOT NULL,"
                         "class int NOT NULL,"
                         "sex char(1) NOT NULL,"
                         "birthday date,"
                         "address VARCHAR(25));"))      //创建inf表
    {
        cout<<"Error:"<<mysql_error(&data)<<endl;
        exit(0);
    }
    this->id="SELECT * FROM inf WHERE id";
    this->passwd="SELECT * FROM inf WHERE passwd";
    this->name="SELECT * FROM inf WHERE name";
    this->Class="SELECT * FROM inf WHERE class";
    this->sex="SELECT * FROM inf WHERE sex";
    this->birthday="SELECT * FROM inf WHERE birthday";
    this->address="SELECT * FROM inf WHERE address";
    this->result= nullptr;
    this->Create="INSERT INTO inf(id,passwd,name,class,sex,birthday,address)VALUES";
    //初始化SQL拼接字符串
}

SqlLinker::~SqlLinker()
{
    mysql_close(&data);     //关闭链接
}

int SqlLinker::CreateNewStudent(char *name, int id, int Class, Date birthday, char *address, char sex, int passwd)
{
    string sql=this->id+"="+to_string(id)+";";
    const char *cmd=(char*)sql.data();
    mysql_query(&data,cmd);
    this->result=mysql_store_result(&data);     //检查对应ID是否已经存在
    if(this->result!= nullptr)
    {
        return 0;
    } else{
        string insert=this->Create+*name+","+to_string(id)+","+to_string(Class)+","+birthday.to_string()+","+*address+","+sex+","+to_string(passwd)+");";
        char *p=(char*)insert.data();
        mysql_query(&data,p);   //创建表项
        return 1;
    }
}
