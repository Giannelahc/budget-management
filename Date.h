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
              void showDate(){
                char buffer[50];
                strftime(buffer, sizeof(buffer), "%A, %d de %B de %Y - %H:%M", &date);
                cout << "Date: " << buffer << endl;
            }

};
