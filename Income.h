#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "DateManager.h"

using namespace std;

class Income {
    int incomeId;
    int userId;
    int date;
    string reason;
    float quota;

public:
    Income (int incomeId = 0, int userId = 0, int date = 0, string reason = "", float quota = 0) {
        this -> incomeId = incomeId;
        this -> userId = userId;
        this -> date = date;
        this -> reason = reason;
        this -> quota = quota;
    }
    int getIncomeId();
    int getUserId();
    int getDate();
    string getReason();
    float getQuota();
    void setIncomeId(int newId);
    void setUserId(int newLoggedUserId);
    void setDate(int newDate);
    void setReason(string newName);
    void setQuota(float newQuota);
};

#endif
