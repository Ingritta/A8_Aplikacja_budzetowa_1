#include "ApplicationManager.h"

void ApplicationManager::userRegistration() {
    userManager.userRegistration();
}

void ApplicationManager::showAllUsers() {
    userManager.showAllUsers();
}

void ApplicationManager::userLogin() {
    userManager.userLogin();
    if (userManager.checkIfUserIsLogged () == false) {
        transactionManager = new TransactionManager(NAME_OF_FILE_WITH_TRANSACTIONS, userManager.getLoggedUserId());
    }
}

void ApplicationManager::changePasswordOfLoggedUser() {
    userManager.changePasswordOfLoggedUser();
}

void ApplicationManager::userLogout() {
    userManager.userLogout();
    delete transactionManager;
    transactionManager = NULL;
}

char ApplicationManager::selectOptionFromMainMenu() {
    return userManager.selectOptionFromMainMenu();
}

char ApplicationManager::selectOptionFromUserMenu() {
    return transactionManager->selectOptionFromUserMenu();
}

bool ApplicationManager::checkIfUserIsLogged () {
    return userManager.checkIfUserIsLogged ();
}

void ApplicationManager::addDetailsOfTransaction() {
    transactionManager->addDetailsOfTransaction();
}
