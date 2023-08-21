#include "TransactionManager.h"

int TransactionManager::getNewTransactionId() {//dopisany

    if (transactions.empty() == true)
        return 1;
    else
        return transactions.back().getTransactionId() + 1;
}

int TransactionManager::getNewExpenseId() {//dopisany

    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getExpenseId() + 1;
}


void TransactionManager::setAmountOfIncomesTransactions(int newAmountOfTransactions) {
    if (newAmountOfTransactions >= 0) {
        this -> amountOfIncomesTransactions = newAmountOfTransactions;
    }
}

void TransactionManager::setAmountOfExpensesTransactions(int newAmountOfTransactions) {
    if (newAmountOfTransactions >= 0) {
        this -> amountOfExpensesTransactions = newAmountOfTransactions;
    }
}

void TransactionManager::setChoosenBeginDate(int newChoosenBeginDate) {
    if (newChoosenBeginDate >= 0) {
        this -> choosenBeginDate = newChoosenBeginDate;
    }
}

void TransactionManager::setEndDate(int newEndDate) {
    if (newEndDate >= 0) {
        this -> endDate = newEndDate;
    }
}

char TransactionManager::selectOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj wplyw" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    //printAllTransactions();
    //showAllTransactions();//?
    choice = SupportiveMethods::loadChar();

    return choice;
}

void TransactionManager::addDetailsOfIncomeTransaction() {
    Transaction transaction;
    system("cls");
    cout << " >>> DODAWANIE NOWEJ TRANSAKCJI <<<" << endl << endl;
    transaction = giveDataOfNewIncomeTransaction();
    transactions.push_back(transaction);
    transactionFile.addTransactionToFile(transaction);
}

void TransactionManager::addDetailsOfExpenseTransaction() {
    Expense expense;
    system("cls");
    cout << " >>> DODAWANIE NOWEJ TRANSAKCJI <<<" << endl << endl;
    expense = giveDataOfNewExpenseTransaction();
    expenses.push_back(expense);
    expenseFile.addExpenseToFile(expense);
}

Transaction TransactionManager::giveDataOfNewIncomeTransaction() {
    Transaction transaction;

    string writtenQuota = "";

    transaction.setTransactionId(getNewTransactionId());
    transaction.setUserId(LOGGED_USER_ID);
    transaction.setDate(askAboutDate());

    cout << "Podaj zrodlo wplywu: ";
    transaction.setReason(SupportiveMethods::getLine());

    transaction.setQuota(correctQuota());

    return transaction;
}

Expense TransactionManager::giveDataOfNewExpenseTransaction() {
    Expense expense;
    string writtenQuota = "";

    expense.setExpenseId(getNewExpenseId());
    expense.setUserId(LOGGED_USER_ID);
    expense.setDate(askAboutDate());

    cout << "Przeznaczenie : ";
    expense.setReason(SupportiveMethods::getLine());

    expense.setQuota(correctQuota());

    return expense;
}


float TransactionManager::correctQuota() {
    string writtenQuota = "";
    float quota = 0;
    do {
        cout << "Podaj kwote: ";
        writtenQuota = SupportiveMethods::getLine();
    } while (!checkWrittenQuota(writtenQuota));

    quota = SupportiveMethods::convertStringToFloat(writtenQuota);

    return quota;
}

bool TransactionManager::checkWrittenQuota(string writtenQuota) {
    int k = 0;
    if (writtenQuota.length() == 0) {
        return false;
    }
    size_t position = writtenQuota.find(',');
    for (unsigned int i = 0; i < writtenQuota.length(); i++) {
        if (writtenQuota[i] == ',') {
            writtenQuota.replace(position, 1, ".");
            k++;
        } else if(!isdigit(writtenQuota[i]) && writtenQuota[i] != '.') {
            cout << "Wpisano nieprawidlowa wartosc" << endl;
            return false;
        } else if (writtenQuota[i] == '.') {
            k++;
        } else if (k > 1) {
            cout << "Wpisano nieprawidlowa wartosc" << endl;
            return false;
        }
    }
    return  true;
}

void TransactionManager::printDetailsOfIncomeTransaction(Transaction transaction) {
    cout << endl << "Id transakcji:                " << transaction.getTransactionId() << endl;
    cout << "Id uzytkownika:                       " << transaction.getUserId() << endl;
    cout << "Data transakcji:                      " << dateManager.addDashes(transaction.getDate()) << endl;
    cout << "Zrodlo:                               " << transaction.getReason() << endl;
    cout << "Kwota:                                " << setprecision(2) << fixed << transaction.getQuota() << endl;
}

void TransactionManager::printDetailsOfExpenseTransaction(Expense expense) {
    cout << endl << "Id transakcji:                " << expense.getExpenseId() << endl;
    cout << "Id uzytkownika:                       " << expense.getUserId() << endl;
    cout << "Data transakcji:                      " << dateManager.addDashes(expense.getDate()) << endl;
    cout << "Przeznaczenie:                        " << expense.getReason() << endl;
    cout << "Kwota:                                " << setprecision(2) << fixed << expense.getQuota() << endl;
}

int TransactionManager::askAboutDate() {
    int dateOfTransaction = 0;
    string date = "";
    cout << "Jezeli chcesz wpisac date inna niz dzisiejsza wpisz 't', jesli nie wcisnij dowolny klawisz." << endl;
    if(SupportiveMethods::loadChar() == 't') {
        do {
            cout << "Podaj date: ";
            dateManager.setWrittenDate(SupportiveMethods::getLine());
            date = dateManager.getWrittenDate();
        } while (!dateManager.checkIfDateIsWrittenProperly(date) || !dateManager.checkDetailsOfWrittenDate());
        dateOfTransaction = SupportiveMethods::cutDashes(date);
    } else {
        dateOfTransaction = SupportiveMethods::cutDashes(dateManager.getDateFromOs());
        cout << "Data transakcji: " << dateManager.getDateFromOs() << endl;
    }
    return dateOfTransaction;
}

int TransactionManager::getChoosenBeginDate() {
    return choosenBeginDate;
}

int TransactionManager::getEndDate() {
    return endDate;
}

void TransactionManager::printCurrentMonthBalance() {
    float incomesBalance = 0, expensesBalance = 0, balance = 0;
    system("cls");

    choosenBeginDate = dateManager.countFirstDayOfCurrentMonth();

    cout <<"choosenBeginDate" << choosenBeginDate << endl;
    while(getChoosenBeginDate() <= SupportiveMethods::cutDashes(dateManager.getDateFromOs())) {
        incomesBalance += countIncomesBalance(transactions);
        choosenBeginDate++;
    }
    cout <<"choosenBeginDate" << choosenBeginDate << endl;
    choosenBeginDate = dateManager.countFirstDayOfCurrentMonth();
    cout <<"choosenBeginDate" << choosenBeginDate << endl;
    while(getChoosenBeginDate() <= SupportiveMethods::cutDashes(dateManager.getDateFromOs())) {
        expensesBalance += countExpensesBalance(expenses);
        choosenBeginDate++;
    }
    cout <<"choosenBeginDate" << choosenBeginDate << endl;
    balance = incomesBalance - expensesBalance;
    printIncomeBalance(incomesBalance);
    printExpenseBalance(expensesBalance);
    printBalance(balance);
    system ("pause");
}

void TransactionManager::printLastMonthBalance() {
    float incomesBalance = 0, expensesBalance = 0, balance = 0;
    system("cls");

    choosenBeginDate = SupportiveMethods::convertStringToInt(dateManager.countLastMonth());
    while(choosenBeginDate < dateManager.countFirstDayOfCurrentMonth()) {
        incomesBalance += countIncomesBalance(transactions);
        choosenBeginDate++;
    }
    choosenBeginDate = SupportiveMethods::convertStringToInt(dateManager.countLastMonth());
    while(choosenBeginDate < dateManager.countFirstDayOfCurrentMonth()) {
        expensesBalance += countExpensesBalance(expenses);
        choosenBeginDate++;
    }
    balance = incomesBalance - expensesBalance;
    printIncomeBalance(incomesBalance);
    printExpenseBalance(expensesBalance);
    printBalance(balance);
    system ("pause");
}

void TransactionManager::printBalanceForChoosenPeriod() {
    float incomesBalance = 0, expensesBalance = 0, balance = 0;
    system("cls");

    cout << "Podaj date poczatkowa: " << endl;
    choosenBeginDate = askAboutDate();
    setChoosenBeginDate(choosenBeginDate);
    int beginDate = choosenBeginDate;

    cout << "Podaj date koncowa: " << endl;
    endDate = askAboutDate();
    setEndDate(endDate);

    while(beginDate <= getEndDate()) {
        incomesBalance += countIncomesBalance(transactions);
        beginDate++;
    }
    beginDate = choosenBeginDate;
    while(beginDate <= getEndDate()) {
        expensesBalance += countExpensesBalance(expenses);
        beginDate++;
    }
    balance = incomesBalance - expensesBalance;
    printIncomeBalance(incomesBalance);
    printExpenseBalance(expensesBalance);
    printBalance(balance);
    system ("pause");
}

float TransactionManager::countIncomesBalance(vector <Transaction> transactions) { //wczesniej pobrac i uporzadkowac vector
    float currentMonthBalance = 0;

    for (vector <Transaction>::iterator  itr = transactions.begin(); itr != transactions.end(); itr++) {
        if (itr -> getDate() == getChoosenBeginDate()) {
            printDetailsOfIncomeTransaction(*itr);
            currentMonthBalance += itr -> getQuota();
            amountOfIncomesTransactions++;
        }
    }
    return currentMonthBalance;
}

float TransactionManager::countExpensesBalance(vector <Expense> expenses) { //wczesniej pobrac i uporzadkowac vector
    float currentMonthBalance = 0;

    for (vector <Expense>::iterator  itr = expenses.begin(); itr != expenses.end(); itr++) {
        if (itr -> getDate() == getChoosenBeginDate()) {
            printDetailsOfExpenseTransaction(*itr);
            currentMonthBalance += itr -> getQuota();
            amountOfExpensesTransactions++;
        }
    }
    return currentMonthBalance;
}

void TransactionManager::printIncomeBalance(float incomeBalance) {
    cout << "-----------------------------------------------" << endl;
    cout << setprecision(2) << "Suma wplywow wynosi: " << fixed << incomeBalance << endl;
    cout << "-----------------------------------------------" << endl;
}

void TransactionManager::printExpenseBalance(float expenseBalance) {
    cout << "-----------------------------------------------" << endl;
    cout << setprecision(2) << "Suma wydatkow wynosi: " << fixed << expenseBalance << endl;
    cout << "-----------------------------------------------" << endl;
}

void TransactionManager::printBalance(float balance) {
    cout << "-----------------------------------------------" << endl;
    cout << setprecision(2) << "Bilans wynosi: " << fixed << balance << endl;
    cout << "-----------------------------------------------" << endl;
}

void TransactionManager::printAllIncomeTransactions() {
    system("cls");
    if (!transactions.empty()) {
        cout << "     >>> TRANSACJE<<<      " << endl;
        cout << "---------------------------" << endl;
        for (vector <Transaction> :: iterator itr = transactions.begin(); itr != transactions.end(); itr++) {
            printDetailsOfIncomeTransaction(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak wykonanych transakcji." << endl << endl;
    }
    system("pause");
}

void TransactionManager::printAllExpenseTransactions() {
    system("cls");
    if (!expenses.empty()) {
        cout << "     >>> TRANSACJE<<<      " << endl;
        cout << "---------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            printDetailsOfExpenseTransaction(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak wykonanych transakcji." << endl << endl;
    }
    system("pause");
}

void TransactionManager::printComunicateAboutIncomes() {

    if (amountOfTransactions > 0) {
        cout <<  "     >>> TRANSACJE PRZYCHODZACE <<<      " << endl;
    } else
        cout << "Nie zarejestrowano transakcji przychodzacych w danym okresie." << endl;
}
