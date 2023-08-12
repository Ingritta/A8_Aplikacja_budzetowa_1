#include "XmlFile.h"
#include "FileWithUsers.h"
#include "Markup.h"


string XmlFile::getFileName() {
    return NAME_OF_FILE;
}

/*
bool XmlFile::checkIfFileIsEmpty() {
    fstream xmlFile;

    xmlFile.open(NAME_OF_FILE.c_str(), ios::out | ios::app);

    xmlFile.seekg(0, ios::end);
    return xmlFile.tellg() == 0;
}
*/
