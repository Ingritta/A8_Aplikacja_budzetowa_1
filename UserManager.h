#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager {
    int loggedUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User giveDataOfNewUser();
    int getNewUserId();
    bool checkIfLoginExists(string login);

public:
    UserManager(string nameOfFileWithUsers) : fileWithUsers(nameOfFileWithUsers) {
         loggedUserId = 0;
         users = fileWithUsers.readUsersFromFile();
    };
    void userRegistration();
    void showAllUsers();
    void userLogin();
    void changePasswordOfLoggedUser();
    void saveAllUsersInFile();
    char selectOptionFromMainMenu();
    bool checkIfUserIsLogged ();
    int getLoggedUserId();
    void userLogout();
};

#endif
