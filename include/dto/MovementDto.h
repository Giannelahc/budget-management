#include <string.h>
#include "util/Date.h"
#include "model/Category.h"

class MovementDto{
      private:
        int id;
        string description;
        double amount;
        Date transactionDate;
        Date registeredDate;
        int idCategory;
        string nameCategory;
        TransactionType type;
        string nameType;
      public:
        MovementDto(int id, string description, double amount, int idCategory, string nameCategory, TransactionType type,
        Date transactionDate, Date registeredDate);
        string getDescription() const;
        double getAmount() const;
        string getTransactionDate() const;
        string getDate() const;
        int getIdCategory() const;
        string getNameCategory() const;
        TransactionType getType() const;
        string getNameType() const;
        void showMovement();
      
};

