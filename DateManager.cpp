#include <iostream>
#include <ctime>
#include <sstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <conio.h>

#include "DateManager.h"

const string DateManager::getDateFromOs() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[11];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    date = buf;
    cout << date << endl;

    return buf;
}

void DateManager::askAboutDate() {
    //string date = "2022-11-02";
    cout << "Podaj date: " << endl;
    setWrittenDate(SupportiveMethods::getLine());
    checkIfDateIsWrittenProperly();

    cout << writtenDate << endl;
    cout << writtenDate.length() << endl;
}

int DateManager::cutDashes(string date) {
    date = date.erase(4,1);
    date.erase(6,1);
    int dateInt = (atoi(date.c_str()));
    cout << dateInt << endl;

    return dateInt;
}

bool DateManager::checkIfIsLeapYear(string writtenDate) {
    if (convertStringToInt(cutYear(writtenDate))%4 == 0 && (convertStringToInt(cutYear(writtenDate))%100 != 0 || convertStringToInt(cutYear(writtenDate))%400 == 0)) {
        cout << "przestepny" << endl;
        return true;
    } else {
        cout << "nieprzestepny" << endl;

        return false;
    }
}

void DateManager::checkIfDateIsWrittenProperly() {
    if (writtenDate.length() != 10) {
        cout << "Niepoprawna ilosc znakow. Wpisz date w formacie YYYY-MM-DD!" << endl;
    }
    for (size_t signPosition = 0; signPosition <= writtenDate.length(); signPosition++) {
        if (writtenDate[signPosition] == '-') {
            if(signPosition == 4 || signPosition == 7) {
                continue;
            } else {
                cout << "Niepoprawny zapis daty. Wpisz date w formacie YYYY-MM-DD!" << endl;
                break;
            }
        }
    }
    cout << "convertStringToInt(cutYear(date)) " << convertStringToInt(cutYear(date)) << "convertStringToInt(cutYear(writtenDate)) " << convertStringToInt(cutYear(writtenDate)) << endl;
    if (convertStringToInt(cutYear(date)) < convertStringToInt(cutYear(writtenDate))) {
        cout << "Wpisany rok jest nieprawidlowy. Wpisz poprawny rok!" << endl;
    } else if (convertStringToInt(cutMonth(writtenDate)) > 12) {
        cout << "Wpisany miesiac jest nieprawidlowy. Wpisz poprawny miesiac!" << endl;
    } else if (checkIfIsLeapYear(writtenDate) && convertStringToInt(cutMonth(writtenDate)) == 2 && convertStringToInt(cutDay(writtenDate)) > 29) {
        cout << "Wpisany dzien jest nieprawidlowy. Wpisz poprawny dzien!" << endl;
    } else if (!checkIfIsLeapYear(writtenDate) && convertStringToInt(cutMonth(writtenDate)) == 2 && convertStringToInt(cutDay(writtenDate)) > 28) {
        cout << "Wpisany dzien jest nieprawidlowy. Wpisz poprawny dzien!" << endl;
    } else if ((convertStringToInt(cutMonth(writtenDate)) == 4 || convertStringToInt(cutMonth(writtenDate)) == 6 || convertStringToInt(cutMonth(writtenDate)) == 9 || convertStringToInt(cutMonth(writtenDate)) == 11) && convertStringToInt(cutDay(writtenDate)) > 30) {
        cout << "Wpisany dzien jest nieprawidlowy. Wpisz poprawny dzien!" << endl;
    } else if (convertStringToInt(cutDay(writtenDate)) > 31) {
        cout << "Wpisany dzien jest nieprawidlowy. Wpisz poprawny dzien!" << endl;
    }
}

void DateManager::compareDates() {
    int beginDate = cutDashes(date);
    int endDate = cutDashes(writtenDate);
    while (beginDate > endDate) {
        cout << beginDate << "->" << endDate << endl;
        endDate++;
    }
}

int DateManager::countCurrentMonth() {
    int dayInt = convertStringToInt(cutDay(date));
    int searchedDate = cutDashes(date) - dayInt + 1;
    cout << "searchedDate current month" << searchedDate << endl;

    return searchedDate;
}

int DateManager::countLastMonth() {
    string zero = "0", searchedDate = "";
    string year = cutYear(date);

    string month = cutMonth(date);
    int lastMonth = convertStringToInt(month) - 1 ;

    month = convertIntToString(lastMonth);

    if (month.length() > 1) {
        searchedDate = year += month;
    } else {
        searchedDate = year += zero += month;
    }
    int searchedDateInt = convertStringToInt(searchedDate);
    cout << "searchedDate last month" << searchedDate << endl;

    return searchedDateInt;
}

string DateManager::cutYear(string date) {
    string year = "";
    int i = 0;
    while (isdigit(date[i])) {
        year += date[i];
        i++;
    }
    return year;
}

string DateManager::cutMonth(string writtenDate) {
    string month = "";
    int i = 5;
    while (isdigit(writtenDate[i])) {
        month += writtenDate[i];
        i++;
    }
    return month;
}

string DateManager::cutDay(string writtenDate) {
    string day = "";
    int i = 8;
    while (isdigit(writtenDate[i])) {
        day += writtenDate[i];
        i++;
    }
    return day;
}

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

void DateManager::wszystkie() {
    getDateFromOs();
    askAboutDate();
    compareDates();
    countCurrentMonth();
    countLastMonth();
    system ("pause");
}

/*
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
*/
