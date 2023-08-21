#include "Expense.h"

void Expense::setExpenseId(int newExpenseId) {
    if (newExpenseId >= 0) {
        this -> expenseId = newExpenseId;
    }
}

void Expense::setUserId(int LOGGED_USER_ID) {
    if (userId >= 0) {
        this -> userId = LOGGED_USER_ID;
    }
}

void Expense::setDate(int newDate) {
    if (date >= 0)
        this -> date = newDate;
}

void Expense::setReason(string newReason) {
    this -> reason = newReason;
}

void Expense::setQuota(float newQuota) {
    if (quota >= 0) {
        this -> quota = newQuota;
    }
}

int Expense::getExpenseId() {
    return this -> expenseId;
}

int Expense::getUserId() {
    return this -> userId;
}

int Expense::getDate() {
    return this -> date;
}

string Expense::getReason() {
    return this -> reason;
}

float Expense::getQuota() {
    return this -> quota;
}

