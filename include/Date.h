#pragma once
#include <iostream>
#include <ctime>

using namespace std;

class Date{
      private:
              time_t now;
              tm date;
      
      public: 
              Date(){
                     now=time(0);
                     date = *localtime(&now);
              }
              Date(int day, int month, int year, int hour, int minute){
                date = {0};
                date.tm_hour = hour;
                date.tm_min = minute;
                date.tm_mday = day;
                date.tm_mon = month - 1;
                date.tm_year = year - 1900;
              }
              string showDate(){
                char buffer[50];
                strftime(buffer, sizeof(buffer), "%A, %d %B, %Y - %H:%M", &date);
                return string(buffer);
              }

            void serialize(std::ostream& os) const {
              os.write(reinterpret_cast<const char*>(&date), sizeof(date));
            }
      
            void deserialize(std::istream& is) {
                is.read(reinterpret_cast<char*>(&date), sizeof(date));
            }

};
