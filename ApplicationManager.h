#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include <iostream>
#include "UserManager.h"
#include "User.h"
#include "XmlFile.h"
#include "TransactionManager.h"

using namespace std;

class ApplicationManager {
    UserManager userManager;
    TransactionManager *transactionManager;
    DateManager dateManager; //?
    const string NAME_OF_FILE_WITH_TRANSACTIONS;

public:
    ApplicationManager(string nameOfFileWithUsers, string nameOfFileWithTransactions) : userManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_TRANSACTIONS (nameOfFileWithTransactions) {
        transactionManager = NULL;
    };
    ~ApplicationManager() {
        delete transactionManager;
        transactionManager = NULL;
    };
    void userRegistration();
    void readUsersFromFile();
    void changePasswordOfLoggedUser();
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
    bool checkIfUserIsLogged();
    void userLogout();
    int getLoggedUserId();
    void userLogin();
    void showAllUsers();
    void addDetailsOfTransaction();
};

#endif

