#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <string>

#include "SupportiveMethods.h"
#include "Transaction.h"
#include "XmlFile.h"

using namespace std;

class TransactionFile {

protected:

    const string NAME_OF_FILE;
    int lastTransactionId;

public:
    TransactionFile(string nameOfFile) : NAME_OF_FILE(nameOfFile) {}
    string getFileName();
    bool checkIfFileIsEmpty();
    void addTransactionToFile(Transaction transactions);
    int getLastTransactionId();
    vector <Transaction> readTransactionsOfLoggedUserFromFile(int loggedUserId);
};

#endif
