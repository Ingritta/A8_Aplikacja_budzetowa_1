#include <iostream>
#include "ApplicationManager.h"
#include "Markup.h"//?

using namespace std;

int main() {
    ApplicationManager ApplicationManager ("Users.xml", "Transactions.xml");

    char choice;

    while (true) {
        if (ApplicationManager.checkIfUserIsLogged()) {

            choice = ApplicationManager.selectOptionFromMainMenu();

            switch (choice) {
            case '1':
                ApplicationManager.userRegistration();
                ApplicationManager.showAllUsers();
                break;
            case '2':
                ApplicationManager.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {

            choice = ApplicationManager.selectOptionFromUserMenu();

            switch (choice) {
            case '1':
                ApplicationManager.addDetailsOfTransaction();
                break;
            case '2':
                // ApplicationManager.searchContactByName();
                break;
            case '3':
                ApplicationManager.printCurrentMonthBalance();
                break;
            case '4':
                //ApplicationManager.printAllContacts();
                break;
            case '5':
                //ApplicationManager.removeContact();
                break;
            case '6':
                ApplicationManager.changePasswordOfLoggedUser();
                break;
            case '7':
                ApplicationManager.userLogout();
                break;
            }
        }
    }
    return 0;
}


