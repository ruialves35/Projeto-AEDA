#include "Date.h"
#include <iomanip>      // std::setw

using namespace std;

Date::Date(): year(0), month(0), day(0){}

Date::Date(unsigned int year, unsigned int month, unsigned int day): year(year), month(month), day(day)
{}

unsigned int Date::getYear() const { return year; }

unsigned int Date::getMonth() const { return month; }

unsigned int Date::getDay() const { return day; }

void Date::setDay(unsigned int day) {
    this->day = day;
}

void Date::setMonth(unsigned int month) {
    this->month = month;
}

void Date::setYear(unsigned int year) {
    this->year = year;
}

void Date::show() const {
    cout << setw(2) << setfill('0') << day << "/" << setw(2) << setfill('0') << month << "/" << setw(4) << setfill('0') << year;
}





