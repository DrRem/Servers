//
// Created by fffei on 2019/10/17.
//

#include "Date.h"

Date::Date() {
    this->year=2000;
    this->month=1;
    this->day=1;
}

Date::Date(int year, int month, int day) {
    this->year=year;
    this->month=month;
    this->day=day;
}

void Date::de_serialization(string temp) {
    string year_ = temp.substr(0,3);
    string month_ = temp.substr(4,5);
    string day_ = temp.substr(6,7);
    this->year=stoi(year_);
    this->month=stoi(month_);
    this->day=stoi(day_);
}

string Date::to_serialization() {
    string temp;
    temp=to_string(this->year)+"-";
    if(get_len(this->month) == 1)
    {
        temp=temp+"0"+to_string(this->month)+"-";
    }else{
        temp=temp+to_string(this->month)+"-";
    }
    if(get_len(this->day) == 1)
    {
        temp=temp+"0"+to_string(this->day)+"-";
    }else{
        temp=temp+to_string(this->day)+"-";
    }
    return temp;
}
