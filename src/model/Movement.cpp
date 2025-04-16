#include <model/Movement.h>

Movement::Movement(string description, double amount, Date transactionDate, int idCategory)
    : description(description), amount(amount), transactionDate(transactionDate), idCategory(idCategory)
{
}

string Movement::getDescription() const
{
    return description;
}
double Movement::getAmount() const
{
    return amount;
}
string Movement::getTransactionDate() const
{
    return transactionDate.showDate();
}
string Movement::getDate() const{
    return registeredDate.showDate();
  }
int Movement::getIdCategory() const
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

