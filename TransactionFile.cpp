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

vector <Transaction> TransactionFile::readIncomeTransactionsOfLoggedUserFromFile(int loggedUserId) {
    Transaction transaction;
    vector <Transaction> transactions;
    string dataOfLastTransaction = "";

    if (xml.Load(NAME_OF_FILE)) {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("Transaction")) {
            xml.IntoElem();
            xml.FindElem("TransactionId");
            transaction.setTransactionId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("UserId");
             if (atoi(MCD_2PCSZ(xml.GetData())) == loggedUserId){
                transaction.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("Date");
                transaction.setDate(atoi(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("Reason");
                transaction.setReason(xml.GetData());
                xml.FindElem("Quota");
                transaction.setQuota(SupportiveMethods::convertStringToFloat(MCD_2PCSZ(xml.GetData())));
                xml.OutOfElem();

                transactions.push_back(transaction);
            }
        }
    }
    if (dataOfLastTransaction != "")
       lastTransactionId = transaction.getTransactionId();
    return transactions;
}


/*
Transaction TransactionFile::getDataOfTransaction(int loggedUserId) {
    Transaction transaction;

    if (xml.Load(NAME_OF_FILE)) {
        xml.FindElem();
        xml.IntoElem();
        xml.FindElem("Transacactions");
        xml.IntoElem();
        xml.FindElem("TransacactionId");
        transaction.setTransactionId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("UserId");
        transaction.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("Date");
        transaction.setDate(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("Reason");
        transaction.setReason(xml.GetData());
        xml.FindElem("Quota");
        transaction.setQuota(SupportiveMethods::convertStringToFloat(MCD_2PCSZ(xml.GetData())));
        xml.OutOfElem();
    }
    return transaction;
}
*/
