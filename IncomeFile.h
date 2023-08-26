#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <string>

#include "SupportiveMethods.h"
#include "Income.h"
#include "XmlFile.h"

using namespace std;

class IncomeFile {

     CMarkup xml;

protected:

    const string NAME_OF_FILE;
    int lastIncomeId;

public:

    IncomeFile(string nameOfFile) : NAME_OF_FILE(nameOfFile) {
    lastIncomeId = 0;
    }
    string getFileName();
    bool checkIfFileIsEmpty();
    void addTransactionToFile(Income incomes);
    int getLastIncomeId();
    vector <Income> readIncomeTransactionsOfLoggedUserFromFile(int loggedUserId);
    Income getDataOfTransaction(int loggedUserId);
};

#endif
