//
// Created by fffei on 2019/10/17.
//

#include "Student.h"

Student::Student() {
    this->Class=0;
    this->address=" ";
    this->birthday=" ";
    this->sex=' ';
    this->passwd=" ";
    this->id=0;
    this->name=" ";
}

string Student::serialization() {
    string tmp;
    return tmp;
}

void Student::deserialization() {

}

Student::Student(const char *name, int id, int Class, int year, int month, int day, char sex,
                 const char *passwd) {
    this->name=name;
    this->id=id;
    this->passwd=passwd;
    this->sex=sex;
    this->birthday.year=year;
    this->birthday.month=month;
    this->birthday.day=day;
    this->address=address;
    this->Class=Class;

}
