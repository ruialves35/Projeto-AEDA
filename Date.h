#ifndef AEDA_DATE_H
#define AEDA_DATE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date{
private:
    unsigned int year;
    unsigned int month;
    unsigned int day;
public:
    Date();
    Date(unsigned int year, unsigned int month, unsigned int day);
    unsigned int getYear() const;
    void setYear(unsigned int year) const;
    unsigned int getMonth() const;
    void setMonth(unsigned int month) const;
    unsigned int getDay() const;
    void setDay(unsigned int day) const;
    void show() const;
};


#endif //AEDA_DATE_H
