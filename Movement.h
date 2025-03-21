#include <string.h>
#include "Date.h"

enum TransactionType { EXPENSE, INCOME };
enum Category { HOUSING, TRANSPORTATION, FOOD, CLOTHING, INSURANCE,  MEDICAL, HOUSEHOLD, EDUCATION};

class Movement{
      private:
              string description;
              double amount;
              TransactionType type;
              Date transactionDate;
              Date registeredDate;  
      public:
             Movement(string description_, double amount_, TransactionType type_, 
                Date transactionDate_): description(description_), amount(amount_), type(type_), transactionDate(transactionDate_){}
             
             void showMovement() {
                cout << "Descripci�n: " << description << endl;
                cout << "Monto: " << amount << endl;
                cout << "Tipo: " << type << endl;
                cout << "Fecha de transacci�n: ";
                transactionDate.showDate();
                cout << "Fecha de registro: ";
                registeredDate.showDate();
            }
      
};
