#include "TransactionManager.h"

void TransactionManager::readTransactionsOfLoggedUserFromFile() {
    transactions = transactionFile.readTransactionsOfLoggedUserFromFile(LOGGED_USER_ID);
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
    choice = SupportiveMethods::loadChar();

    return choice;
}

string TransactionManager::checkAndConvertWrittenQuota(string ) {
    int k = 0;
    for (unsigned int i = 0; i < writtenQuota.length(); i++) {
        if (writtenQuota[i] == ',') {
            writtenQuota.replace(findSignPosition(writtenQuota), 1, ".");
            k++;
        } else if(!isdigit(writtenQuota[i]) && writtenQuota[i] != '.') {
            cout << "Wpisano nieprawidlowa wartosc" << endl;
            break;
        } else if (writtenQuota[i] == '.') {
            k++;
        } else if (k > 1) {
            cout << "Wpisano nieprawidlowa wartosc" << endl;
            break;
        }
        //transaction.getQuota(SupportiveMethods::convertStringToFloat(writtenQuota));
    }
    return writtenQuota;
}

void TransactionManager::addDetailsOfTransaction() {
    Transaction transaction;
    system("cls");
    cout << " >>> DODAWANIE NOWEJ TRANSAKCJI <<<" << endl << endl;
    transaction = giveDataOfNewTransaction();
    transactions.push_back(transaction);
    transactionFile.addTransactionToFile(transaction);
}

Transaction TransactionManager::giveDataOfNewTransaction() {
    Transaction transaction;

    //transaction.setTransactionId((transactionFile.getLastTransactionId() + 1));
    //transaction.setLoggedUserId(LOGGED_USER_ID);

    cout << "Podaj zrodlo wplywu: ";
    transaction.setReason(SupportiveMethods::getLine());

    cout << "Podaj kwote: ";
    transaction.setQuota(SupportiveMethods::convertStringToFloat(checkAndConvertWrittenQuota(SupportiveMethods::getLine())));//zmienic string na float

    return transaction;
}

int TransactionManager::findSignPosition(string) {
    size_t position = writtenQuota.find(',');
    if (position != string::npos)
        return position;
}

//cout << setprecision(2) << fixed << quota << endl;


/*
void ContactManager::printAllContacts() {
    system("cls");
    if (!contacts.empty()) {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Contact> :: iterator itr = contacts.begin(); itr != contacts.end(); itr++) {
            printDataOfContact(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void ContactManager::printDataOfContact(Contact contact) {
    cout << endl << "Id:         " << contact.getId() << endl;
    cout << "Imie:               " << contact.getName() << endl;
    cout << "Nazwisko:           " << contact.getSurname() << endl;
    cout << "Numer telefonu:     " << contact.getPhoneNumber() << endl;
    cout << "Email:              " << contact.getEmail() << endl;
    cout << "Adres:              " << contact.getAddress() << endl;
}

bool ContactManager::checkIfContactsAreWritten() {
    return contacts.empty();
}

void ContactManager::addContact() {
    Contact contact;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    contact = giveDataOfNewContact();
    contacts.push_back(contact);
    fileWithContacts.addContactToFile(contact);
}



void ContactManager::setNumberOfContacts(int newAmountOfContacts) {
    if (newAmountOfContacts >= 0) {
        this -> amountOfContacts = newAmountOfContacts;
    }
}

void ContactManager::printNumberOfFoundContacts() {
    if (amountOfContacts == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << amountOfContacts << endl << endl;
}

void ContactManager::searchContactByName() {
    string nameOfSerchedContact = "";
    int amountOfContacts = 0;

    system("cls");
    if (!contacts.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        nameOfSerchedContact = SupportiveMethods::getLine();
        nameOfSerchedContact = SupportiveMethods::replaceFirstLetterForCapitalRestForSmall(nameOfSerchedContact);

        for (vector <Contact>::iterator  itr = contacts.begin(); itr != contacts.end(); itr++) {
            if (itr -> getName() == nameOfSerchedContact) {
                printDataOfContact(*itr);
                amountOfContacts++;
                setNumberOfContacts(amountOfContacts);
            }
        }
        printNumberOfFoundContacts();
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void ContactManager::removeContact() {
    int IdOfRemovingContact = 0, vectorSize = contacts.size(), counter = 0;
    char sign;
    bool checkIfContactExists = false;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;

    IdOfRemovingContact = SupportiveMethods::giveIdOfSelectedContact();

    for (int i = 0; i < vectorSize; i++) {
        if (contacts[i].getId() == IdOfRemovingContact) {
            checkIfContactExists = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            sign = SupportiveMethods::loadChar();

            if(sign == 't') {
                fileWithContacts.removeContactFromFile(IdOfRemovingContact);
                contacts.erase(contacts.begin() + counter);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");

            } else {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
            }
        }
        counter++;
    }
    if (checkIfContactExists == false) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
}

void ContactManager::changeDetailsOfContact() {
    system("cls");
    Contact contact;
    int idOfEditingContact = 0;
    string lineWithContactData = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idOfEditingContact = SupportiveMethods::giveIdOfSelectedContact();

    char choice;
    bool checkIfContactExists = false;

    for (vector <Contact>::iterator  itr = contacts.begin(); itr != contacts.end(); itr++) {
        if (itr -> getId() == idOfEditingContact) {

            checkIfContactExists = true;
            choice = selectOptionFromEditMenu();

            switch (choice) {
            case '1':
                cout << "Podaj nowe imie: ";
                itr -> setName(SupportiveMethods::getLine());
                itr -> setName(SupportiveMethods::replaceFirstLetterForCapitalRestForSmall(itr -> getName()));
                lineWithContactData = fileWithContacts.convertContactDataToLinesWithDataSeparatedByPipes(*itr);
                fileWithContacts.editChoosenLineInFile(lineWithContactData, idOfEditingContact);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                itr -> setSurname(SupportiveMethods::getLine());
                itr -> setSurname(SupportiveMethods::replaceFirstLetterForCapitalRestForSmall(itr -> getSurname()));
                lineWithContactData = fileWithContacts.convertContactDataToLinesWithDataSeparatedByPipes(*itr);
                fileWithContacts.editChoosenLineInFile(lineWithContactData, idOfEditingContact);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                itr -> setPhoneNumber(SupportiveMethods::getLine());
                lineWithContactData = fileWithContacts.convertContactDataToLinesWithDataSeparatedByPipes(*itr);
                fileWithContacts.editChoosenLineInFile(lineWithContactData, idOfEditingContact);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                itr -> setEmail(SupportiveMethods::getLine());
                lineWithContactData = fileWithContacts.convertContactDataToLinesWithDataSeparatedByPipes(*itr);
                fileWithContacts.editChoosenLineInFile(lineWithContactData, idOfEditingContact);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                itr -> setAddress(SupportiveMethods::getLine());
                lineWithContactData = fileWithContacts.convertContactDataToLinesWithDataSeparatedByPipes(*itr);
                fileWithContacts.editChoosenLineInFile(lineWithContactData, idOfEditingContact);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (checkIfContactExists == false) {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}
*/
