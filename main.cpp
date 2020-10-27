#include <iostream>
#include "Date.h"

int testDate(){
    Date d1(29,2,2020);
    cout << d1;
    return 1;
}

int main() {
    testDate();
    return 0;
}

