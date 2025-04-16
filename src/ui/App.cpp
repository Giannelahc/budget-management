#include "ui/App.h"
#include "controller/UserController.h"
#include "ui/MainMenu.h"

void App::run() {
    if (!db.openDatabase("budget.db")) return;
    initDatabase();
    showInitialMenu();
    db.closeDatabase();
}

void App::initDatabase() {
    db.createTablesIfNotExists();
}

void App::showInitialMenu() {
    MainMenu menu;
    menu.show(db);
}
