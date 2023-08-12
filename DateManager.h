#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>

#include "SupportiveMethods.h"

using namespace std;

class DateManager {

    string data;
    string date;
    string writtenDate;
    int dateInt;

public:
    const string getDateFromOs();
    void askAboutDate();
    void divideDate();
    int countCurrentMonth();
    int countLastMonth();
    int cutDashes(string date);
    void checkIfDateIsWrittenProperly();
    bool checkIfIsLeapYear(string writtenDate);
    void compareDates();
    void wszystkie();//?
    //string getWrittenDate();
    string cutYear(string date);
    string cutMonth(string writtenDate);
    string cutDay(string writtenDate);
    void setWrittenDate(string newWrittenDate);
    int convertStringToInt(string data);
    string convertIntToString(int data);
};

#endif

/*
 //int year;
    //int month;
    //int day;
*/
