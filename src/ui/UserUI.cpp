#include "ui/UserUI.h"
#include <iostream>
using namespace std;

void UserUI::showUser(User& user, StorageManagerDb&) {
    cout << "\n\t--- User Info ---\n";
    cout << "\tName: " << user.getName() << "\n";
    cout << "\tBalance: " << user.getBalance() << "\n";
    cout << "\tRegistered on: " << user.getDate() << "\n";
}
