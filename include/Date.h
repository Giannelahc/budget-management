#pragma once
#include <iostream>
#include <ctime>
#include <sstream>

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
              string showDate() const{
                char buffer[50];
                strftime(buffer, sizeof(buffer), "%d/%m/%Y - %H:%M", &date);
                return string(buffer);
              }

            void serialize(std::ostream& os) const {
              os.write(reinterpret_cast<const char*>(&date), sizeof(date));
            }
      
            void deserialize(std::istream& is) {
                is.read(reinterpret_cast<char*>(&date), sizeof(date));
            }

            static Date parseDate(const std::string& dateString) {
              int day, month, year, hour, minute;
              char slash1, slash2, dash, colon;
          
              std::istringstream ss(dateString);
              
              ss >> day >> slash1 >> month >> slash2 >> year >> dash >> hour >> colon >> minute;
          
              if (slash1 != '/' || slash2 != '/' || dash != '-' || colon != ':') {
                  throw std::runtime_error("Invalid date format");
              }
              return Date(day, month, year, hour, minute);
            }

            static Date parseDateFormat2(const std::string& dateString) {
              int day, month, year;
              char slash1, slash2;
          
              std::istringstream ss(dateString);
              
              ss >> day >> slash1 >> month >> slash2 >> year;
          
              if (slash1 != '/' || slash2 != '/') {
                  cout<<"Invalid format, please type again dd/MM/yyyy: ";
              }
              return Date(day, month, year, 0, 0);
            }

};
