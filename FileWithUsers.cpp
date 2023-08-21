#include "FileWithUsers.h"

vector <User> FileWithUsers::readUsersFromFile() {

    User user;
    vector <User> users;

    if (xml.Load(NAME_OF_FILE)) {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("User")) {
            xml.IntoElem();
            xml.FindElem("UserId");
            user.setId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("Login");
            user.setLogin(xml.GetData());
            xml.FindElem("Password");
            user.setPassword(xml.GetData());
            xml.OutOfElem();

            users.push_back(user);
        }
    }
    return users;
}

void FileWithUsers::addUserToFile (User user) {

    bool fileExists = xml.Load(NAME_OF_FILE);

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(NAME_OF_FILE);
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.Save(NAME_OF_FILE);
}

void FileWithUsers::changeData(string data) {
    if (xml.Load(NAME_OF_FILE)) {
        xml.FindElem();
        xml.IntoElem();
        xml.FindElem("User");
        xml.ResetMainPos();
        while (xml.FindElem()){
            xml.RemoveElem();
        }
        xml.FindElem();
        xml.IntoElem();
         xml.FindElem("User");
        xml.AddElem("Password", "data");
        xml.Save(NAME_OF_FILE);
    }
}

/*
void FileWithUsers::saveAllUsersInFile(vector <User> &users) {

    CMarkup xml;

    vector <User>::iterator itrEnd = --users.end();

    bool fileExists = xml.Load(NAME_OF_FILE);

    if (fileExists) {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
            xml.FindElem();
            xml.IntoElem();
            xml.AddElem("User");
            xml.IntoElem();
            xml.AddElem("UserId", itr->getId());
            xml.AddElem("Login", itr->getLogin());
            xml.AddElem("Password", itr->getPassword());
            xml.Save(NAME_OF_FILE);
        }
    } else {

        cout << "Nie mozna otworzyc pliku " << NAME_OF_FILE << endl;
    }
    xml.Save(NAME_OF_FILE);
}
*/

/*
User FileWithUsers::getDataOfUser() {
    User user;
    //user = readUsersFromFile();
    int numberOfsingleDataOfUser = 1;

    while (1) {
        switch(numberOfsingleDataOfUser) {
        case 1:
            user.setId();
            break;
        case 2:
            user.setLogin();
            break;
        case 3:
            user.setPassword();
            break;
        }
        numberOfsingleDataOfUser++;
    }
}
return user;
}


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

*/

