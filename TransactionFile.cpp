#include "TransactionFile.h"
#include "TransactionManager.h"
#include "SupportiveMethods.h"

string TransactionFile::getFileName() {
    return NAME_OF_FILE;
}

int TransactionFile::getLastTransactionId() {
    return lastTransactionId;
}

void TransactionFile::addTransactionToFile(Transaction transaction) {

}

vector <Transaction> TransactionFile::readTransactionsOfLoggedUserFromFile(int loggedUserId) {

}
