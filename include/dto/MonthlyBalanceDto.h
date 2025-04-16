#ifndef MONTHLY_BALANCE_DTO_H
#define MONTHLY_BALANCE_DTO_H

#include <string>

class MonthlyBalanceDto {
private:
    std::string month;
    double balance;

public:
    MonthlyBalanceDto(const std::string& month, double balance)
        : month(month), balance(balance) {}

    std::string getMonth() const {
        return month;
    }

    double getBalance() const {
        return balance;
    }

    void setMonth(const std::string& newMonth) {
        month = newMonth;
    }

    void setBalance(double newBalance) {
        balance = newBalance;
    }
};

#endif
