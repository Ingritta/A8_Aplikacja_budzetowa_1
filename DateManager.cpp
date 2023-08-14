#include <iostream>
#include <ctime>
#include <sstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <conio.h>

#include "DateManager.h"
#include "Date.h"

const string DateManager::getDateFromOs() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[11];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    date = buf;
    //cout << date << endl;

    return buf;
}

bool DateManager::checkIfDateIsWrittenProperly(string writtenDate) {
    if (writtenDate.length() != 10) {
        cout << "Niepoprawna ilosc znakow. Wpisz date w formacie YYYY-MM-DD!" << endl;
        return false;
    }
    for (size_t signPosition = 0; signPosition <= writtenDate.length(); signPosition++) {
        if (writtenDate[signPosition] == '-') {
            if(signPosition == 4 || signPosition == 7) {
                continue;
            } else {
                cout << "Niepoprawny zapis daty. Wpisz date w formacie YYYY-MM-DD!" << endl;
                return false;
            }
        }
    }
    return true;
}

int DateManager::checkDetailsOfWrittenDate() {
    if (cutYear(getDateFromOs()) < cutYear(writtenDate)) {
        cout << "Wpisany rok jest nieprawidlowy. Wpisz poprawny rok!" << endl;
        return false;
    } else if (cutMonth(writtenDate) > 12) {
        cout << "Wpisany miesiac jest nieprawidlowy. Wpisz poprawny miesiac!" << endl;
        return false;
    } else if (checkIfIsLeapYear() && cutMonth(writtenDate) == 2 && cutDay(writtenDate) > 29) {
        cout << "Wpisany dzien jest nieprawidlowy. Wpisz poprawny dzien!" << endl;
        return false;
    } else if (!checkIfIsLeapYear() && cutMonth(writtenDate) == 2 && cutDay(writtenDate) > 28) {
        cout << "Wpisany dzien jest nieprawidlowy. Wpisz poprawny dzien!" << endl;
        return false;
    } else if ((cutMonth(writtenDate) == 4 || cutMonth(writtenDate) == 6 || cutMonth(writtenDate) == 9 || cutMonth(writtenDate) == 11) && cutDay(writtenDate) > 30) {
        cout << "Wpisany dzien jest nieprawidlowy. Wpisz poprawny dzien!" << endl;
        return false;
    } else if (cutDay(writtenDate) > 31) {
        cout << "Wpisany dzien jest nieprawidlowy. Wpisz poprawny dzien!" << endl;
        return false;
    }
    return true;
}

void DateManager::setWrittenDate(string newWrittenDate) {
    writtenDate = newWrittenDate;
}

string DateManager::getWrittenDate() {
    return writtenDate;
}

bool DateManager::checkIfIsLeapYear() {
    if (cutYear(writtenDate)%4 == 0 && (cutYear(writtenDate)%100 != 0 || cutYear(writtenDate)%400 == 0)) {
        //cout << "przestepny" << endl;
        return true;
    } else {
        //cout << "nieprzestepny" << endl;
        return false;
    }
}

void DateManager::compareDates() {
    int beginDate = SupportiveMethods::cutDashes(date);
    int endDate = SupportiveMethods::cutDashes(writtenDate);
    while (beginDate > endDate) {
        //cout << beginDate << "->" << endDate << endl;
        endDate++;
    }
}

int DateManager::countCurrentMonth() {
    int searchedDate = SupportiveMethods::cutDashes(date) - cutDay(date) + 1;
    //cout << "searchedDate current month" << searchedDate << endl;
    return searchedDate;
}

int DateManager::countLastMonth() {
    string zero = "0", searchedDate = "";
    string year = SupportiveMethods::convertIntToString(cutYear(date));
    string month = SupportiveMethods::convertIntToString(cutMonth(date));

    int lastMonth = SupportiveMethods::convertStringToInt(month) - 1 ;

    month = SupportiveMethods::convertIntToString(lastMonth);

    if (month.length() > 1) {
        searchedDate = year += month;
    } else {
        searchedDate = year += zero += month;
    }
    int searchedDateInt = SupportiveMethods::convertStringToInt(searchedDate);
    //cout << "searchedDate last month" << searchedDate << endl;

    return searchedDateInt;
}

int DateManager::cutYear(string date) {
    int i = 0, yearInt = 0;
    string year = "";
    while (isdigit(date[i])) {
        year += date[i];
        i++;
    }
    yearInt = stoi(year);
    return  yearInt;
}

int DateManager::cutMonth(string date) {
    string month = "";
    int i = 5, monthInt = 0;
    while (isdigit(writtenDate[i])) {
        month += writtenDate[i];
        i++;
    }
    monthInt = stoi(month);
    return monthInt;
}

int DateManager::cutDay(string writtenDate) {
    string day = "";
    int i = 8, dayInt = 0;
    while (isdigit(writtenDate[i])) {
        day += writtenDate[i];
        i++;
    }
    dayInt = stoi(day);
    return dayInt;
}
/*
void DateManager::setWrittenDate(string newWrittenDate) {
    writtenDate = newWrittenDate;
}

int DateManager::convertStringToInt(string data) {
    int dataInt = (atoi(data.c_str()));

    return dataInt;
}

string DateManager::convertIntToString(int data) {
    ostringstream ss;
    ss << data;
    string str = ss.str();

    return str;
}
*/
/*
void DateManager::wszystkie() {
    getDateFromOs();
    askAboutDate();
    compareDates();
    countCurrentMonth();
    countLastMonth();
    system ("pause");
}


void DateManager::divideDate() {
    string singleData = "";
    int numberOfSingleData = 1;

    for (int signPosition = 0; signPosition <= 10; signPosition++) {
        if (signPosition != 4 && signPosition != 7 && signPosition != 10) {
            singleData += signPosition;// date[signPosition]
        } else {
            switch(numberOfSingleData) {
            case 1:
                year = (atoi(singleData.c_str()));
                break;
            case 2:
                month = (atoi(singleData.c_str()));
                break;
            case 3:
                day = (atoi(singleData.c_str()));
                break;
            }
            singleData = "";
            numberOfSingleData++;
        }
    }
}


int DateManager::cutYear() {
    int year = 0, date = 0;
    for (int i = 0; i < 5;  i++) {
        year += date[i];
    }
    return year;
}

int DateManager::cutMonth() {
    int month = 0, date = 0;
    for (int i = 5; i < 7;  i++) {
        month += date[i];
    }
    return month;
}

int DateManager::cutDay() {
    int day = 0, date = 0;
    for (int i = 7; i = 8;  i++) {
        day += date[i];
    }
    return day;
}
*/
/*
int DateManager::askAboutDate() {
    //string date = "2022-11-02";
    cout << "Czy transakcja zostala wykonana dzisiaj? Wpiszt t (tak) lub n (nie).: " << endl;

    if(SupportiveMethods::loadChar() == 't') {
        dateFromOS = cutDashes(getDateFromOs());
    } else {
        do {
            cout << "Podaj date w ktorej dokonano transakcji: " << endl;
        } while (!checkIfDateIsWrittenProperly(SupportiveMethods::getLine()));
        if (checkIfDateIsWrittenProperly(SupportiveMethods::getLine()));
        dateInt = cutDashes(SupportiveMethods::getLine());
    }
    return dateInt;
}
*/
