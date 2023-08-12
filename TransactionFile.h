#ifndef TRANSACTIONFILE_H
#define TRANSACTIONFILE_H

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
    void addTransactionToFile(Transaction transaction);
    int getLastTransactionId();
    vector <Transaction> readTransactionsOfLoggedUserFromFile(int loggedUserId);
};

#endif