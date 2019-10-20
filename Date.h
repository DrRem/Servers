//
// Created by fffei on 2019/10/17.
//

#ifndef SERVERS_DATE_H
#define SERVERS_DATE_H
#include "SqlLinker.h"
#include "get_len.h"
class Date {
public:
    int year,month,day;
    Date();
    Date(int year,int month, int day);
    string to_serialization();
    void de_serialization(string temp);
};


#endif //SERVERS_DATE_H
