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
    const string NAME_OF_FILE_WITH_TRANSACTIONS;
    const string NAME_OF_FILE_WITH_EXPENSES;

public:
    ApplicationManager(string nameOfFileWithUsers, string nameOfFileWithTransactions, string nameOfFileWithExpenses) : userManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_TRANSACTIONS (nameOfFileWithTransactions), NAME_OF_FILE_WITH_EXPENSES (nameOfFileWithExpenses) {
        transactionManager = NULL;
    };
    ~ApplicationManager() {
        delete transactionManager;
        transactionManager = NULL;
    };
    void userRegistration();
    void changePasswordOfLoggedUser();
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
    bool checkIfUserIsLogged();
    void userLogout();
    int getLoggedUserId();
    void userLogin();
    //void showAllUsers();
    void addDetailsOfIncomeTransaction();
    void addDetailsOfExpenseTransaction();
    void printCurrentMonthBalance();
    void printLastMonthBalance();
    void printBalanceForChoosenPeriod();
};

#endif

