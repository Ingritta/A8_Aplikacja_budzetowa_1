#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#include <iomanip>
#include <cctype>

#include <cstdlib>
#include <string>
#include <algorithm>
#include <conio.h>

#include "TransactionFile.h"
#include "ExpenseFile.h"
#include "Transaction.h"
#include "Expense.h"
#include "SupportiveMethods.h"
#include "DateManager.h"

using namespace std;

class TransactionManager {

    const int LOGGED_USER_ID;
    vector <Transaction> transactions;
    vector <Expense> expenses;
    TransactionFile transactionFile;
    ExpenseFile expenseFile;
    int amountOfIncomesTransactions;//?
    int amountOfExpensesTransactions;//?
    int choosenBeginDate;
    int endDate;
    const string NAME_OF_FILE;
    Transaction giveDataOfNewIncomeTransaction();
    Expense giveDataOfNewExpenseTransaction();

public:
    TransactionManager(string nameOfFileWithTransactions, string nameOfFileWithExpenses, int loggedUserId) : transactionFile(nameOfFileWithTransactions), expenseFile(nameOfFileWithExpenses), LOGGED_USER_ID(loggedUserId) {
        loggedUserId = 0;
        transactions = transactionFile.readIncomeTransactionsOfLoggedUserFromFile(LOGGED_USER_ID);
        expenses = expenseFile.readExpenseTransactionsOfLoggedUserFromFile(LOGGED_USER_ID);
        amountOfIncomesTransactions = 0;
        amountOfExpensesTransactions = 0;
    };
    DateManager dateManager;
    void setChoosenBeginDate(int newChoosenBeginDate);
    void setEndDate(int newEndDate);
    int getTransactionId();
    int getNewExpenseId();
     int getNewTransactionId();
     int getChoosenBeginDate();
     int getEndDate();
    void setAmountOfIncomesTransactions(int newAmountOfTransactions);
    void setAmountOfExpensesTransactions(int newAmountOfTransactions);
    void addDetailsOfIncomeTransaction();
    void addDetailsOfExpenseTransaction();
    void readTransactionsOfLoggedUserFromFile();
    bool checkIfDataIsWritten();
    char selectOptionFromUserMenu();
    void printCurrentMonthBalance();
    void removeTransaction();
    void changeDetailsOfTransaction();
    void printDetailsOfIncomeTransaction(Transaction transaction);
    void printDetailsOfExpenseTransaction(Expense expense);
    int askAboutDate();
    bool checkWrittenQuota(string writtenQuota);
    float correctQuota();
    float countIncomesBalance(vector <Transaction> transactions);
    float countExpensesBalance(vector <Expense> expenses);
    void printLastMonthBalance();
    void printBalanceForChoosenPeriod();
    void countFirstDayOfCurrentMonth();
    void printIncomeBalance(float incomeBalance);
    void printExpenseBalance(float expenseBalance);
    void printBalance(float balance);
    void showAllTransactions();//??
    void countCurrentMonthBalance(int choosenBeginDate, int endDate);
     void printAllIncomeTransactions();
     void printAllExpenseTransactions();
};



#endif
