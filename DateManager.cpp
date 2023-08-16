#include "DateManager.h"

const string DateManager::getDateFromOs() {
    string date = "";
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[11];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    date = buf;

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
    if (SupportiveMethods::cutDashes(getDateFromOs()) < SupportiveMethods::cutDashes(writtenDate)) {
        cout << "Wpisany rok jest nieprawidlowy - data trasakcji jest pozniejsza od dzaty dzisiejszej. Wpisz poprawny rok!" << endl;
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
        return true;
    } else {
        return false;
    }
}

void DateManager::compareDates() {
    while (SupportiveMethods::cutDashes(getDateFromOs()) > SupportiveMethods::cutDashes(writtenDate)) {
        //cout << beginDate << "->" << endDate << endl;
        SupportiveMethods::cutDashes(writtenDate) + 1;
    }
}

int DateManager::countFirstDayOfCurrentMonth() {
    int searchedDate = SupportiveMethods::cutDashes(getDateFromOs()) - cutDay(getDateFromOs()) + 1;
    //cout << "searchedDate current month" << searchedDate << endl;
    return searchedDate;
}

int DateManager::countLastMonth() {
    string zero = "0", searchedDate = "";
    string year = SupportiveMethods::convertIntToString(cutYear(getDateFromOs()));
    string month = SupportiveMethods::convertIntToString(cutMonth(getDateFromOs()));
    string day = SupportiveMethods::convertIntToString(cutDay(getDateFromOs()));

    int lastMonth = SupportiveMethods::convertStringToInt(month) - 1 ;

    if (month.length() > 1) {
        searchedDate = year += month += day;
    } else {
        searchedDate = year += zero += month += day;
    }
    int searchedDateInt = SupportiveMethods::convertStringToInt(searchedDate);
    cout << "searchedDate last month" << searchedDate << endl;

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

string DateManager::addDashes(int date) {
    string dateWithDashes = SupportiveMethods::convertIntToString(date);
    string year, month, day;

    for (int i = 0; i < 4; i++) {
        year += dateWithDashes[i];
    }
    for (int i = 4; i < 6; i++) {
        month += dateWithDashes[i];
    }
    for (int i = 6; i < 8; i++) {
        day += dateWithDashes[i];
    }

    dateWithDashes = year + '-' + month + '-' + day;

    return dateWithDashes;
}
