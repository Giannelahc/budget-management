#ifndef USER_H
#define USER_H

#include <string.h>
#include "util/Date.h"
class User {
       private:
        int id;
              string name;
              string password;
              double balance;
              Date registeredDate;
      public:
              User();
             User(string& name_, double balance);
             User(int id, string& name_, string& password, double balance, Date registeredDate);
             int getId() const;
             string getName() const;
             void setName(string& name);
             double getBalance() const;
             void setBalance(double balance);
             string getPassword() const;
             void setPassword(string password);
             void setRegisteredDate(Date date);
             string getDate() const;
             void serialize(std::ostream& os) const;
              void deserialize(std::istream& is);
              
};

#endif