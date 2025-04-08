#include <Movement.h>

Movement::Movement(string description, double amount, Date transactionDate, int idCategory)
    : description(description), amount(amount), transactionDate(transactionDate), idCategory(idCategory)
{
}
string Movement::getDescription()
{
    return description;
}
double Movement::getAmount()
{
    return amount;
}
Date Movement::getTransactionDate()
{
    return transactionDate;
}
int Movement::getIdCategory()
{
    return idCategory;
}
void Movement::showMovement()
{
    cout << "Description: " << description << endl;
    cout << "Amount: " << amount << endl;
    //cout << "Type: " << type << endl;
    cout << "Transaction Date: ";
    transactionDate.showDate();
    cout << "Registered Date: ";
    registeredDate.showDate();
}

