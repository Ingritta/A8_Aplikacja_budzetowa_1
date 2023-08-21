#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>

using namespace std;

class ExpensesFile {
protected:

    const string NAME_OF_FILE;

public:
    ExpensesFile(string nameOfFile) : NAME_OF_FILE(nameOfFile) {}
    string getFileName();
    bool checkIfFileIsEmpty();
};

#endif
