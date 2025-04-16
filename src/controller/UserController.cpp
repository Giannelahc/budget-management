#include "controller/UserController.h"
#include "service/UserService.h"
#include "model/Category.h"
#include "dao/CategoryDaoDb.h"
#include <iostream>
#include <algorithm>
#include <conio.h>

using namespace std;

void UserController::registerUser(User& user, StorageManagerDb& storageManagerDb) {
    string name;
    double amount;
    Date date;

    cout << "\n\t***USER***\n";
    cout << "\n\tName: ";
    cin.ignore();
    getline(cin, name);
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    user.setName(name);
    user.setPassword(getHiddenPassword());
    //cin.clear();
    cout << "\n\tInitial balance: ";
    cin >> amount;

    user.setBalance(amount);
    user.setRegisteredDate(date);

    UserService userService;
    userService.registerUser(user, storageManagerDb);

    vector<Category> defaultCategories = {
        Category("EDUCATION", TransactionType::OUTCOME),
        Category("TRANSPORTATION", TransactionType::OUTCOME),
        Category("ENTERTAINMENT", TransactionType::OUTCOME),
        Category("HEALTH", TransactionType::OUTCOME),
        Category("FOOD", TransactionType::OUTCOME),
        Category("HOUSING", TransactionType::OUTCOME),
        Category("DEPOSIT", TransactionType::INCOME),
        Category("TRANSFER", TransactionType::INCOME)
    };

    CategoryDaoDb categoryDaoDb;
    categoryDaoDb.saveCategories(defaultCategories, storageManagerDb);
}

bool UserController::login(User& user, StorageManagerDb& storageManagerDb) {
    string name, passwordHashed;
    system("cls");
    cout << "\n\t******LOG IN******\n";
    cout << "\n\tName: ";
    getline(cin, name);
    transform(name.begin(), name.end(), name.begin(), ::toupper);

    passwordHashed = UserService::hashPassword(getHiddenPassword());
    return user.getName() == name && user.getPassword() == passwordHashed;
}

std::string UserController::getHiddenPassword() {
    std::string password;
    char ch;
    cout << "\tPassword: ";
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!password.empty()) {
                password.pop_back();
                std::cout << "\b \b";
            }
        } else {
            password.push_back(ch);
            std::cout << '*';
        }
    }
    return password;
}