#include <string.h>
#include "Date.h"

class Movement{
      private:
        string description;
              double amount;
              Date transactionDate;
              Date registeredDate;
              int idCategory;
      public:
        Movement(string description, double amount,
        Date transactionDate, int idCategory);
        string getDescription();
        double getAmount();
        Date getTransactionDate();
        int getIdCategory();
        void showMovement();
      
};

