#ifndef AEDA_DATE_H
#define AEDA_DATE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Date{
private:
    unsigned int year;
    unsigned int month;
    unsigned int day;
    map<int, int> months_map;

public:
    Date();
    Date(unsigned int year, unsigned int month, unsigned int day);
    void setMap();
    bool isValid();
    bool isLeap() const;
    map<int, int> getMap() const;
    unsigned int getYear() const;
    void setYear(int year);
    unsigned int getMonth() const;
    void setMonth(int month);
    unsigned int getDay() const;
    void setDay(int day);
    void show() const;
};


#endif //AEDA_DATE_H
