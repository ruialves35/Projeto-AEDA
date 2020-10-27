#include "Date.h"
#include <iomanip>      // std::setw

using namespace std;

Date::Date(): day(0), month(0), year(0){ setMap(); }

Date::Date(unsigned int day, unsigned int month, unsigned int year) : day(0), month(0), year(0){
    Date d1;
    d1.setYear(year); d1.setMonth(month); d1.setDay(day);
    setMap();
    if (d1.isValid()){
        this->year = year; this->month = month; this->day = day;
    }
    else{
        cout << "This date is invalid. The date was initialized has 00/00/0000" << endl;
    }
}

void Date::setMap(){
    months_map[1] = 31;
    months_map[3] = 31;
    months_map[5] = 31;
    months_map[7] = 31;
    months_map[8] = 31;
    months_map[10] = 31;
    months_map[12] = 31;
    months_map[4] = 30;
    months_map[6] = 30;
    months_map[9] = 30;
    months_map[11] = 30;
    if (isLeap()){ //ano bissexto
        months_map[2] = 29;
    }
    else{
        months_map[2] = 28;
    }
}

bool Date::isValid() {
    if (year < 0) return false;
    if (month <= 0 || month > 12) return false;
    if (day <= 0 || day > months_map[month]) return false;
    return true;
}

bool Date::isLeap() const {
    if (year == 0 ) return false;
    if (year %4 == 0){
        if (year % 100 == 0){
            if (year % 400 == 0) return true;
            else return false;
        }
        else return true;
    }
    else return false;
}

map<int, int> Date::getMap() const {
    return months_map;
}

unsigned int Date::getYear() const { return year; }

unsigned int Date::getMonth() const { return month; }

unsigned int Date::getDay() const { return day; }

void Date::setDay(int day) {
    if (day < 0 ){
        cout << "Invalid day, date was not changed. Do it again with a positive number." << endl;
        return;
    }
    else if (day > months_map[month]){
        cout << "Invalid day, this month has not so much days. Date was not changed. Do it again!" << endl;
        return;
    }
    this->day = day;
}

void Date::setMonth(int month) {
    if (month < 0 || month > 12) {
        cout << "Invalid month, date was not changed. Do it again with a real month" << endl;
        return;
    }
    this->month = month;
}

void Date::setYear(int year) {
    if (year < 0){
        cout << "Invalid year, date was not changed. Do it again with a real year." << endl;
        return;
    };
    this->year = year;
    setMap();
}

void Date::show() const {
    cout << setw(2) << setfill('0') << day << "/" << setw(2) << setfill('0') <<
         month << "/" << setw(4) << setfill('0') << year << endl;
}





