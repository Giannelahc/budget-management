#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "model/User.h"
#include "util/StorageManagerDb.h"

class MainMenu {
public:
    static void show(StorageManagerDb& storageManagerDb);
    static void showUserMenu(User& user, StorageManagerDb& storageManagerDb);
};

#endif
