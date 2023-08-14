#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include "DateManager.h"

using namespace std;

class Transaction {
    int transactionId;
    int userId;
    int date;
    string reason;
    float quota;

public:
    Transaction (int transactionId = 0, int userId = 0, int date = 0, string reason = "", float quota = 0) {
        this -> transactionId = transactionId;
        this -> userId = userId;
        this -> date = date;
        this -> reason = reason;
        this -> quota = quota;
    }
    int getTransactionId();
    int getUserId();
    int getDate();
    string getReason();
    float getQuota();
    void setTransactionId(int newId);
    void setLoggedUserId(int newLoggedUserId);
    void setDate(int newDate);
    void setReason(string newName);
    void setQuota(float newQuota);
};

#endif
