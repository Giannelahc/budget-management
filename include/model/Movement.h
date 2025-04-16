#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <string.h>
#include "util/Date.h"

class Movement{
      private:
        int id;
        string description;
        double amount;
        Date transactionDate;
        Date registeredDate;
        int idCategory;
      public:
        Movement(string description, double amount,
        Date transactionDate, int idCategory);
        string getDescription() const;
        double getAmount() const;
        string getTransactionDate() const;
        string getDate() const;
        int getIdCategory() const;
        void showMovement();
      
};

#endif