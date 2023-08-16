#include "TransactionFile.h"
#include "TransactionManager.h"
#include "SupportiveMethods.h"

string TransactionFile::getFileName() {
    return NAME_OF_FILE;
}

int TransactionFile::getLastTransactionId() {
    return lastTransactionId;
}

void TransactionFile::addTransactionToFile(Transaction transaction) {//nazwa pliku

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
    xml.AddElem("Date", transaction.getDate());
    xml.AddElem("Reason", transaction.getReason());
    xml.AddElem("Quota", transaction.getQuota());
    xml.Save(NAME_OF_FILE);
    lastTransactionId++;
}

vector <Transaction> TransactionFile::readTransactionsOfLoggedUserFromFile(int loggedUserId) {
    CMarkup xml;

    vector <Transaction> transactions;
    Transaction transaction;

    xml.Load("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    bool fileExists = xml.Load(NAME_OF_FILE);

    if (fileExists) {
        xml.IntoElem();

        while (xml.FindElem("Transacactions")) {

            xml.IntoElem();
            if (xml.FindElem("Transacaction")) {
                xml.IntoElem();
                xml.FindElem("TransacactionId");
                transaction.setTransactionId(atoi(xml.GetData().c_str()));
                xml.FindElem("UserId");
                transaction.setUserId(atoi(xml.GetData().c_str()));
                xml.FindElem("Date");
                transaction.setDate(atoi(xml.GetData().c_str()));
                xml.FindElem("Reason");
                transaction.setReason (xml.GetData());
                xml.FindElem("Quota");
                transaction.setQuota(SupportiveMethods::convertStringToFloat(xml.GetData().c_str()));
                transactions.push_back(transaction);
                xml.OutOfElem();
            } else {

                cout << "Nie mozna otworzyc pliku " << NAME_OF_FILE << endl;

            }
        }
    }
    return transactions;
}


