#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "SupportiveMethods.h"
#include "TextFile.h"

using namespace std;

class FileWithUsers : public TextFile {
    string convertUserDataToLinesWithDataSeparatedByPipes(User user);
    User getDataOfUser(string dataOfSingleUserSeparatedByPipes);

public:
    FileWithUsers(string nameOfFile) : TextFile(nameOfFile) {};
    void addUserToFile(User user);
    vector <User> readUsersFromFile();
    void saveAllUsersInFile(vector <User> &users);
};

#endif
