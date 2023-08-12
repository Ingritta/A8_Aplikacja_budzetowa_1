#include "Transaction.h"

void Transaction::setTransactionId(int newTransactionId) {
    if (newTransactionId >= 0) {
        this -> transactionId = newTransactionId;
    }
}

void Transaction::setLoggedUserId(int LOGGED_USER_ID) {
    if (userId >= 0) {
        this -> userId = LOGGED_USER_ID;
    }
}

void Transaction::setReason(string newReason) {
    this -> reason = newReason;
}

void Transaction::setQuota(float newQuota) {
    if (quota >= 0) {
        this -> quota = newQuota;
    }
}

int Transaction::getTransactionId() {
    return this -> transactionId;
}

int Transaction::getUserId() {
    return this -> userId;
}

string Transaction::getReason() {
    return this -> reason;
}

float Transaction::getQuota() {
    return this -> quota;
}

