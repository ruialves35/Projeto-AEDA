#include <iostream>
#include "Date.h"

int testDate(){
    Date d1(29,2,2019);
    d1.show();
    return 1;
}

int main() {
    testDate();
    return 0;
}

