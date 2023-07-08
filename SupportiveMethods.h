#ifndef SUPPORTIVEMETHODS_H
#define SUPPORTIVEMETHODS_H

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

class SupportiveMethods {
public:
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    static string getNumber(string text, int signPosition);
    static string getLine();
    static string replaceFirstLetterForCapitalRestForSmall(string text);
    static char loadChar();
    static int loadInteger();
    static int giveIdOfSelectedContact();
};

#endif
