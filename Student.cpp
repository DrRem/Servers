//
// Created by fffei on 2019/10/17.
//

#include "Student.h"

Student::Student(){
    this->Class=0;
    this->address=" ";
    this->sex=' ';
    this->passwd=" ";
    this->id=0;
    this->name=" ";
}

string Student::serialization() {       //序列化学生类
    string tmp;
    tmp=to_string(this->id)+"+"+this->passwd+"+"+
            this->name+"+"+to_string(this->Class)+"+"+this->sex+"+"+
            this->birthday.to_serialization()+"+"+this->address;

    return tmp;
}

void Student::deserialization(string tmp) {           //反序列化
    int i[6];
    int j=0;
    while ((i[j]=tmp.find_first_of('+',i[j]))!=string::npos)
    {
        j++;
    }
    this->id = stoi(tmp.substr(0,i[0]-1));
    this->passwd = tmp.substr(i[0],i[1]-1);
    this->name = tmp.substr(i[1],i[2]-1);
    this->Class = stoi(tmp.substr(i[2],i[3]-1));
    this->sex = tmp[i[3]];
    this->birthday.de_serialization(tmp.substr(i[4],i[5]-1));
    this->address = tmp.substr(i[5]);
}

Student::Student(const char *name, int id, int Class, int year, int month, int day, char sex, const char *address,
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
