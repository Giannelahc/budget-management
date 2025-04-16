#ifndef MOVEMENT_UI_H
#define MOVEMENT_UI_H

#include "model/User.h"
#include "util/StorageManagerDb.h"

class MovementUI {
public:
    static void registerMovement(User& user, StorageManagerDb& storageManagerDb);
    static void listMovements(StorageManagerDb& storageManagerDb);
};

#endif
