#include "dto/MovementDto.h"
#include <iomanip>

MovementDto::MovementDto(int id, string description, double amount, int idCategory, string nameCategory, 
    TransactionType type, Date transactionDate, Date registeredDate) : id(id), description(description), amount(amount), idCategory(idCategory),
    nameCategory(nameCategory), type(type), transactionDate(transactionDate), registeredDate(registeredDate)
{
}

double MovementDto::getAmount() const
{
    return amount;
}

string MovementDto::getTransactionDate() const
{
    return transactionDate.showDate();
}

string MovementDto::getDate() const
{
    return registeredDate.showDate();
}

int MovementDto::getIdCategory() const
{
    return idCategory;
}

string MovementDto::getNameCategory() const
{
    return nameCategory;
}

TransactionType MovementDto::getType() const
{
    return type;
}

string MovementDto::getNameType() const
{
    if(type == 0) {
        return "INCOME";
    } else {
        return "OUTCOME";
    }
}

void MovementDto::showMovement()
{
    std::cout << std::setw(3) << id
                << std::setw(20) << description
                << std::setw(10) << amount 
                << std::setw(10) << getNameType()
                << std::setw(15) << getNameCategory() 
                << std::setw(20) << transactionDate.showDate()
                << std::setw(20) << registeredDate.showDate()
                << std::endl;
}

string MovementDto::getDescription() const
{
    return description;
}
