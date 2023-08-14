#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>

#include "SupportiveMethods.h"
#include "Date.h"
#include "Transaction.h"

using namespace std;

class DateManager {

private:
    string data;//?
    int dateFromOS;
    string writtenDate;
    string date;

public:

    const string getDateFromOs();
    bool checkIfDateIsWrittenProperly(string writtenDate);
    int checkDetailsOfWrittenDate();
    int countCurrentMonth();
    int countLastMonth();
    bool checkIfIsLeapYear();
    void compareDates();
    int cutDashes(string date);
    int cutYear(string writtenDate);
    int cutMonth(string writtenDate);
    int cutDay(string writtenDate);
    void setWrittenDate(string newWrittenDate);
    string getWrittenDate();
};

#endif

/*
 //int year;
    //int month;
    //int day;
*/
