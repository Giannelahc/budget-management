#ifndef USER_H
#define USER_H

#include <string.h>
#include "Date.h"
class User {
       private:
        int id;
              string name;
              double balance;
              Date registeredDate;
      public:
              User();
             User(string& name_, double balance);
             User(int id, string& name_, double balance, Date registeredDate);
             int getId() const;
             string getName() const;
             void setName(string& name);
             double getBalance() const;
             void setBalance(double balance);
             void setRegisteredDate(Date date);
             string getDate() const;
             void serialize(std::ostream& os) const;
              void deserialize(std::istream& is);
              
};

#endif