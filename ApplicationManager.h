#ifndef A_H
#define ADDRESSBOOK_H

#include <iostream>
#include "UserManager.h"
#include "User.h"
#include "TextFile.h"

using namespace std;

class ApplicationManager {
    UserManager userManager;
    ContactManager *contactManager;
    const string NAME_OF_FILE_WITH_CONTACTS;

public:
   ApplicationManager(string nameOfFileWithUsers, string nameOfFileWithContacts) :  userManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_CONTACTS(nameOfFileWithContacts) {
        contactManager = NULL;
    };
    ~ApplicationManager() {
        delete contactManager;
        contactManager = NULL;
    };
    void userRegistration();
    void readUsersFromFile();
    void changePasswordOfLoggedUser();
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
    void addContact();
    void readContactsOfLoggedUserFromFile();
    void printAllContacts();
    bool checkIfUserIsLogged();
    bool checkIfContactsAreWritten();
    void userLogout();
    int getLoggedUserId();
    void userLogin();
    void showAllUsers();
    void searchContactByName();
    void searchContactBySurname();
    void removeContact();
    void changeDetailsOfContact();
};

#endif

