#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <string>

#include "SupportiveMethods.h"
#include "Expense.h"
#include "XmlFile.h"

using namespace std;

class ExpenseFile {

     CMarkup xml;

protected:

    const string NAME_OF_FILE;
    int lastExpenseId;

public:

    ExpenseFile(string nameOfFile) : NAME_OF_FILE(nameOfFile) {
    lastExpenseId = 0;
    }
    string getFileName();
    bool checkIfFileIsEmpty();
    void addExpenseToFile(Expense expense);
    int getLastExpenseId();
    vector <Expense> readExpenseTransactionsOfLoggedUserFromFile(int loggedUserId);
    Expense getDataOfTransaction(int loggedUserId);
};

#endif
