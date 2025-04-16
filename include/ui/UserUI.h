#ifndef USER_UI_H
#define USER_UI_H

#include "model/User.h"
#include "util/StorageManagerDb.h"

class UserUI {
public:
    static void showUser(User& user, StorageManagerDb& storageManagerDb);
};

#endif
