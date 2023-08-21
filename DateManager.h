#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <ctime>
#include <sstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <conio.h>

#include "SupportiveMethods.h"
#include "Transaction.h"

using namespace std;

class DateManager {

private:

    int dateFromOS;
    string writtenDate;

public:

    const string getDateFromOs();
    bool checkIfDateIsWrittenProperly(string writtenDate);
    int checkDetailsOfWrittenDate();
    int countFirstDayOfCurrentMonth();
    string countLastMonth();
    bool checkIfIsLeapYear();
    void compareDates();
    int cutDashes(string date);
    int cutYear(string writtenDate);
    int cutMonth(string writtenDate);
    int cutDay(string writtenDate);
    void setWrittenDate(string newWrittenDate);
    string getWrittenDate();
    string addDashes(int date);
};

#endif

