#include <string.h>
#include "Date.h"
class User {
       private:
              string name;
              double amount;
              Date registeredDate;
      public:
              User() {}
             User(string name_, double amount_): name(name_), amount(amount_){}
             string getName(){
                    return name;
             }
             void setName(string name_){
                     this->name = name_;
             }
             double getAmount(){
                    return amount;
             }
             void setAmount(double amount_){
                     this->amount = amount_;
       }
             void printDate(){
                  registeredDate.showDate();
             }
              
};
