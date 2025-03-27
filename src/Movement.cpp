#include <Movement.h>

Movement::Movement(string description_, double amount_, TransactionType type_, 
    Date transactionDate_): description(description_), amount(amount_), type(type_), transactionDate(transactionDate_){}

void Movement::setCategory(Category category)
{
    this->category = category;
}

void Movement::showMovement()
{
    cout << "Description: " << description << endl;
    cout << "Amount: " << amount << endl;
    cout << "Type: " << type << endl;
    cout << "Transaction Date: ";
    transactionDate.showDate();
    cout << "Registered Date: ";
    registeredDate.showDate();
}