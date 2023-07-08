#include "TextFile.h"
#include "FileWithUsers.h"

bool TextFile::checkIfFileIsEmpty() {
    fstream textFile;

    textFile.open(NAME_OF_FILE.c_str(), ios::out | ios::app);

    textFile.seekg(0, ios::end);
    return textFile.tellg() == 0;
}

string TextFile::getFileName() {
    return NAME_OF_FILE;
}

