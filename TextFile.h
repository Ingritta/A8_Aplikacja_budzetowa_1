#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>

using namespace std;

class TextFile {
protected:

    const string NAME_OF_FILE;

public:
    TextFile(string nameOfFile) : NAME_OF_FILE(nameOfFile) {}
    string getFileName();
    bool checkIfFileIsEmpty();
};

#endif
