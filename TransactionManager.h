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
#include "Transaction.h"
#include "SupportiveMethods.h"
#include "DateManager.h"

using namespace std;

class TransactionManager {

    const int LOGGED_USER_ID;
    vector <Transaction> transactions;
    TransactionFile transactionFile;
    int amountOfTransactions;
    const string NAME_OF_FILE;
    Transaction giveDataOfNewTransaction();

public:
    TransactionManager(string nameOfFileWithTransactions, int loggedUserId) : transactionFile(nameOfFileWithTransactions), LOGGED_USER_ID(loggedUserId) {
    loggedUserId = 0;
    transactions = transactionFile.readTransactionsOfLoggedUserFromFile(LOGGED_USER_ID);
    };
    DateManager dateManager;
    void addDetailsOfTransaction();
    void readTransactionsOfLoggedUserFromFile();
    bool checkIfDataIsWritten();
    char selectOptionFromUserMenu();
    void printAllTransactions();
    void printAmountOfTransactions();
    void removeTransaction();
    void changeDetailsOfTransaction();
    void printDetailsOfTransaction(Transaction transaction);
    void setAmountOfTransactions(int newAmountOfTransactions);
    int getTransactionId();
    int getDate();//?
    int askAboutDate();
};

#endif

//TextFile(string nameOfFile) : NAME_OF_FILE(nameOfFile) {}
//string getFileName();
//bool checkIfFileIsEmpty();
//dataOfIncomeSeparatedByPipes : string

/*
using namespace std;

class ContactManager {
    const int LOGGED_USER_ID;
    vector <Contact> contacts;
    FileWithContacts fileWithContacts;
    int amountOfContacts;
    string dataOfContactSeparatedByPipes;

    Contact giveDataOfNewContact();
    void printDataOfContact(Contact adresat);
    void setNumberOfContacts(int newNumberOfContacts);
    char selectOptionFromEditMenu();

public:
    ContactManager(string nameOfFileWithContacts, int loggedUserId) : LOGGED_USER_ID(loggedUserId), fileWithContacts(nameOfFileWithContacts)  {
        loggedUserId = 0;
        contacts = fileWithContacts.readContactsOfLoggedUserFromFile(LOGGED_USER_ID);
    };
    void addContact();
    void readContactsOfLoggedUserFromFile();
    bool checkIfContactsAreWritten();
    char selectOptionFromUserMenu();
    int getContactId();
    void printAllContacts();
    void searchContactByName();
    void searchContactBySurname();
    void printNumberOfFoundContacts();
    void removeContact();
    void changeDetailsOfContact();
};

#endif
*/
