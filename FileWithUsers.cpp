#include "FileWithUsers.h"

void FileWithUsers::addUserToFile (User user) {
    string lineWithUserData = "";
    fstream textFile;
    textFile.open(NAME_OF_FILE.c_str(), ios::app);

    if (textFile.good() == true) {
        lineWithUserData = convertUserDataToLinesWithDataSeparatedByPipes(user);

        if (checkIfFileIsEmpty() == true) {
            textFile << lineWithUserData;
        } else {
            textFile << endl << lineWithUserData;
        }
    } else
       cout << "Nie udalo sie otworzyc pliku " << NAME_OF_FILE << " i zapisac w nim danych." << endl;
    textFile.close();
}

string FileWithUsers::convertUserDataToLinesWithDataSeparatedByPipes(User user) {
    string lineWithUserData = "";
    lineWithUserData += SupportiveMethods::convertIntToString(user.getId())+ '|';
    lineWithUserData += user.getLogin() + '|';
    lineWithUserData += user.getPassword() + '|';

    return lineWithUserData;
}

vector <User> FileWithUsers::readUsersFromFile() {
    User user;
    vector <User> users;
    string dataOfSingleUserSeparatedByPipes = "";
    fstream textFile;

    textFile.open(NAME_OF_FILE.c_str(), ios::in);

    if (textFile.good() == true) {
        while (getline(textFile, dataOfSingleUserSeparatedByPipes)) {
            user = getDataOfUser(dataOfSingleUserSeparatedByPipes);
            users.push_back(user);
        }
        textFile.close();
    }
    return users;
}

User FileWithUsers::getDataOfUser(string dataOfSingleUserSeparatedByPipes) {
    User user;
    string singleDataOfUser = "";
    int numberOfsingleDataOfUser = 1;

    for (size_t signPosition = 0; signPosition < dataOfSingleUserSeparatedByPipes.length(); signPosition++) {
        if (dataOfSingleUserSeparatedByPipes[signPosition] != '|') {
            singleDataOfUser += dataOfSingleUserSeparatedByPipes[signPosition];
        } else {
            switch(numberOfsingleDataOfUser) {
            case 1:
                user.setId(atoi(singleDataOfUser.c_str()));
                break;
            case 2:
                user.setLogin(singleDataOfUser);
                break;
            case 3:
                user.setPassword(singleDataOfUser);
                break;
            }
            singleDataOfUser = "";
            numberOfsingleDataOfUser++;
        }
    }
    return user;
}

void FileWithUsers::saveAllUsersInFile(vector <User> &users)
{
    fstream textFile;
    string lineWithUserData = "";
    vector <User>::iterator itrEnd = --users.end();

    textFile.open(NAME_OF_FILE.c_str(), ios::out);

    if (textFile.good() == true) {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {

            lineWithUserData = convertUserDataToLinesWithDataSeparatedByPipes(*itr);

            if (itr == itrEnd) {
                textFile << lineWithUserData;
            } else {
                textFile << lineWithUserData << endl;
            }
            lineWithUserData = "";
        }
    } else {

        cout << "Nie mozna otworzyc pliku " << NAME_OF_FILE << endl;
    }
    textFile.close();
}
