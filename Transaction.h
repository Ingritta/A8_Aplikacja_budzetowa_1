#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction {
    int transactionId;
    int userId;
    string reason;
    float quota;

public:
    Transaction (int transactionId = 0, int userId = 0, string reason = "", float quota = 0) {
        this -> transactionId;
        this -> userId = userId;
        this -> reason = reason;
        this -> quota = quota;
    }
    int getTransactionId();
    int getUserId();
    string getReason();
    float getQuota();
    void setTransactionId(int newId);
    void setLoggedUserId(int newLoggedUserId);
    void setReason(string newName);
    void setQuota(float newQuota);
};

#endif
