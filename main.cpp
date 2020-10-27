#include <iostream>
#include "Date.h"

int testDate(){
    Date d1;
    d1.show();
    d1.setDay(27);
    d1.setMonth(10);
    d1.setYear(2020);
    d1.show();
    d1.setYear(20);
    d1.show();
    return 1;
}

int main() {
    testDate();
    return 0;
}

