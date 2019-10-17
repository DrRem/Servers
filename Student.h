//
// Created by fffei on 2019/10/17.
//

#ifndef SERVERS_STUDENT_H
#define SERVERS_STUDENT_H

#include "Date.h"

class Student {
public:
    int id,Class;
    string name,passwd,address;
    Date birthday;
    char sex;


    Student();
    Student(const char *name, int id, int Class, int year,int month, int day, char sex, const char *address, const char* passwd);
    string serialization();
    void deserialization(string tmp);
};


#endif //SERVERS_STUDENT_H
