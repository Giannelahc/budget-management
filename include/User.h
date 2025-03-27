#ifndef USER_H
#define USER_H

#include <string.h>
#include "Date.h"
class User {
       private:
              string name;
              double balance;
              Date registeredDate;
      public:
              User();
             User(string& name_, double balance);
             string getName();
             void setName(string& name);
             double getBalance();
             void setBalance(double balance);
             void setRegisteredDate(Date date);
             string getDate();
             void serialize(std::ostream& os) const;
              void deserialize(std::istream& is);
              
};

#endif