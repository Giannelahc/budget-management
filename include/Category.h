#ifndef CATEGORY_H
#define CATEGORY_H

#include "Date.h"

class Category {

    private: 
        int id;
        string name;
        Date registeredDate;
    public:
        Category();
        Category(const string& name);
        Category(int id, const string& name);
        Category(int id, const string& name, Date date);
        string getName() const;
        int getId();
        void setId(int id);
        void setRegisteredDate(Date date);
        string getDate() const;
        void serialize(std::ostream &out) const;
        void deserialize(std::istream& in);
};

#endif