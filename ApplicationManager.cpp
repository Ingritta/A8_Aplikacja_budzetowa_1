#include "ApplicationManager.h"

void ::userRegistration() {
    userManager.userRegistration();
}

void ::showAllUsers() {
    userManager.showAllUsers();
}

void ApplicationManager::userLogin() {
    userManager.userLogin();
    if (userManager.checkIfUserIsLogged () == false) {
        contactManager = new ContactManager(NAME_OF_FILE_WITH_CONTACTS, userManager.getLoggedUserId());
    }
}

void ApplicationManager::changePasswordOfLoggedUser() {
    userManager.changePasswordOfLoggedUser();
}

void ApplicationManager::userLogout() {
    userManager.userLogout();
    delete contactManager;
    contactManager = NULL;
}

char ApplicationManager::selectOptionFromMainMenu() {
    return userManager.selectOptionFromMainMenu();
}

char ApplicationManager::selectOptionFromUserMenu() {
    return contactManager -> selectOptionFromUserMenu();
}

bool ApplicationManager::checkIfContactsAreWritten() {
    return contactManager -> checkIfContactsAreWritten();
}

bool ApplicationManager::checkIfUserIsLogged () {
    return userManager.checkIfUserIsLogged ();
}

void ApplicationManager::searchContactByName() {
    contactManager -> searchContactByName();
}

void ApplicationManager::searchContactBySurname() {
    contactManager -> searchContactBySurname();
}

void ApplicationManager::removeContact() {
    contactManager -> removeContact();
}

void ApplicationManager::changeDetailsOfContact() {
    contactManager -> changeDetailsOfContact();
}
