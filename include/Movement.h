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
              Category category;
      public:
             Movement(string description_, double amount_, TransactionType type_, 
                Date transactionDate_);
             void setCategory(Category category);
             void showMovement();
      
};

