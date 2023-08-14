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

    CMarkup xml;

    bool fileExists = xml.Load(NAME_OF_FILE);

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(NAME_OF_FILE);
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Transaction");
    xml.IntoElem();
    xml.AddElem("TransactionId", transaction.getTransactionId());
    xml.AddElem("UserId", transaction.getUserId());
    xml.AddElem("Reason", transaction.getReason());
    xml.AddElem("Quota", transaction.getQuota());
    xml.Save(NAME_OF_FILE);
}

vector <Transaction> TransactionFile::readTransactionsOfLoggedUserFromFile(int loggedUserId) {

}
