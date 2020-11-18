#include "Date.h"
#include <iomanip>      // std::setw
#include <string>
#include <sstream>  //ostreams
using namespace std;

/**
 * Date default constructor. sets day, month,year to 0.
 */
Date::Date(): day(0), month(0), year(0){ setMap(); }

/**
 * Date constructor
 * @param day Date's day
 * @param month Date's month
 * @param year Date's year
 */
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

/**
 * creates a map with each month days.
 */
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

/**
 * Checks if a date is valid (Day of the corresponding month is correct)
 * @return true if it is valid, false otherwise
 */
bool Date::isValid() {
    if (year < 0) return false;
    if (month <= 0 || month > 12) return false;
    if (day <= 0 || day > months_map[month]) return false;
    return true;
}

/**
 * Checks if a year is leap
 * @return true if is leap, false otherwise
 */
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

/**
 * @return map of the months and each corresponding days
 */
map<int, int> Date::getMonthsMap() const {
    return months_map;
}

/**
 * @return year of the date
 */
unsigned int Date::getYear() const { return year; }

/**
 * @return month of the date
 */
unsigned int Date::getMonth() const { return month; }

/**
 * @return day of the date
 */
unsigned int Date::getDay() const { return day; }

/**
 * sets a day, shows a message if the day is invalid
 * @param new Date's day
 */
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

/**
 * sets a month, shows a message if the month is invalid
 * @param new Date's month
 */
void Date::setMonth(int month) {
    if (month < 0 || month > 12) {
        cout << "Invalid month, date was not changed. Do it again with a real month" << endl;
        return;
    }
    this->month = month;
}

/**
 * sets a year, shows a message if the year is invalid
 * @param new Date's year
 */
void Date::setYear(int year) {
    if (year < 0){
        cout << "Invalid year, date was not changed. Do it again with a real year." << endl;
        return;
    };
    this->year = year;
    setMap();
}

/**
 * Constructs a string with the information of the date in form DD/MM/YYYY
 * @return string with the information
 */
string Date::getInfo() const{
    string info= "";
    if (day < 10) {
        info += "0"+ to_string(day);
        info += "/";
    }
    else info += to_string(day) + "/";

    if (month < 10){
        info += "0" + to_string(month);
        info += "/";
    }
    else info += to_string(month) + "/";

    if (year > 1000) info += to_string(year);
    else if (year < 1000 && year > 100){
        info += "0" + to_string(year);
    }
    else if (year < 100 && year > 10) info += "00" + to_string(year);
    else info += "000" + to_string(year);

    return info;
}

/**
 * Displays the information of a Date
 * @param o ostream were we are going to write the information
 * @param d Date to get information
 * @return ostream with the information
 */
ostream & operator<<(ostream & o, const Date & d)
{
    o << setw(2) << setfill('0') << d.day << "/" << setw(2) << setfill('0') <<
      d.month << "/" << setw(4) << setfill('0') << d.year << endl;
    return o;
}

/**
 * Compares 2 dates (Days, months, years)
 * @param d1 first date to be compared
 * @param d2 second date to be compared
 * @return true if d1 < d2, false otherwise
 */
bool operator < (const Date &d1, const Date &d2){
    if (d1.year < d2.year){
        return true;
    }
    else if (d1.month < d2.month){
        return true;
    }
    else if (d1.day < d2.day){
        return true;
    }
    else return false;
}



/**
 * Compares 2 dates (Days, months, years)
 * @param d1 first date to be compared
 * @param d2 second date to be compared
 * @return true if d1 = d2, false otherwise
 */
bool operator == (const Date &d1, const Date &d2){
    if (d1.year == d2.year){
        if (d1.month == d2.month){
            if (d1.day == d2.day){
                return true;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}
