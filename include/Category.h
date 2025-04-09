#ifndef CATEGORY_H
#define CATEGORY_H

#include "Date.h"

enum TransactionType { 
    INCOME = 0,
    OUTCOME = 1
};

class Category {

    private: 
        int id;
        string name;
        TransactionType type;
        Date registeredDate;
    public:
        Category();
        Category(const string& name, TransactionType transactionType);
        Category(int id, const string& name, TransactionType transactionType);
        Category(int id, const string &name, TransactionType transactionType, Date date);
        string getName() const;
        TransactionType getType() const;
        void setType(TransactionType t);
        int getId();
        void setId(int id);
        void setRegisteredDate(Date date);
        string getDate() const;
        void showCategory();
        void serialize(std::ostream &out) const;
        void deserialize(std::istream& in);
};

#endif