#pragma once
#include "util/StorageManagerDb.h"
#include "model/User.h"

class App {
public:
    void run();

private:
    StorageManagerDb db;
    //User currentUser;
    void initDatabase();
    void showInitialMenu();
};