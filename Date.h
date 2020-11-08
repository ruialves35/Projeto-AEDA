#ifndef AEDA_DATE_H
#define AEDA_DATE_H

#include <iostream>
#include <iomanip> //std::setw
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
    Date(unsigned int day, unsigned int month, unsigned int year);
    void setMap();
    bool isValid();
    bool isLeap() const;
    map<int, int> getMonthsMap() const;
    unsigned int getYear() const;
    void setYear(int year);
    unsigned int getMonth() const;
    void setMonth(int month);
    unsigned int getDay() const;
    void setDay(int day);
    string getInfo() const;
    friend ostream& operator << (ostream& o, const Date &d);
    friend bool operator < (const Date &d1, const Date &d2);
};


#endif //AEDA_DATE_H
