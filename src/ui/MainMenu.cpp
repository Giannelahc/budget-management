#include "ui/MainMenu.h"
#include "controller/UserController.h"
#include "ui/MovementUI.h"
#include "ui/CategoryUI.h"
#include "ui/ReportUI.h"
#include "ui/UserUI.h"
#include "dao/UserDaoDb.h"

#include <iostream>
#include <conio.h>
using namespace std;

void MainMenu::show(StorageManagerDb& storageManagerDb) {
    User user;
    UserDaoDb userDaoDb;
    vector<User> users = userDaoDb.getUsers(storageManagerDb);

    if (users.empty()) {
        int opc;
        do {
            system("cls");
            cout << "\n\t******WELCOME******\n";
            cout << "\t1. Register user\n";
            cout << "\t2. Exit\n";
            cout << "\tOption: ";
            cin >> opc;

            if (opc == 1) {
                system("cls");
                UserController::registerUser(user, storageManagerDb);
                showUserMenu(user, storageManagerDb);
            }

        } while (opc!=2);
    } else {
        user = users[0];
        if (UserController::login(user, storageManagerDb)) {
            showUserMenu(user, storageManagerDb);
        } else {
            cout << "\n\tInvalid credentials\n";
            system("pause");
        }
    }
}

void MainMenu::showUserMenu(User& user, StorageManagerDb& storageManagerDb) {
    int opc;
    do {
        system("cls");
        cout << "\n\tWELCOME " << user.getName() << "\n";
        cout << "\n\t1. Register transaction\n";
        cout << "\t2. Register new category\n";
        cout << "\t3. List categories\n";
        cout << "\t4. Show balance\n";
        cout << "\t5. List movements\n";
        cout << "\t6. Summary reports\n";
        cout << "\t7. Quit\n";
        cout << "\tOption: ";
        cin >> opc;

        switch (opc) {
            case 1: system("cls"); MovementUI::registerMovement(user, storageManagerDb); break;
            case 2: system("cls"); CategoryUI::registerCategory(storageManagerDb); break;
            case 3: system("cls"); CategoryUI::showCategories(storageManagerDb); break;
            case 4: system("cls"); UserUI::showUser(user, storageManagerDb); break;
            case 5: system("cls"); MovementUI::listMovements(storageManagerDb); break;
            case 6: system("cls"); ReportUI::showMonthlyBalanceGraph(storageManagerDb); break;
        }
        if (opc != 7) getch();

    } while (opc != 7);
}
