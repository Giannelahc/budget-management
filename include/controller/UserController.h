#ifndef USER_CONTROLLER_H
#define USER_CONTROLLER_H

#include "model/User.h"
#include "util/StorageManagerDb.h"

class UserController {
public:
    static void registerUser(User& user, StorageManagerDb& storageManagerDb);
    static bool login(User& user, StorageManagerDb& storageManagerDb);
    static std::string getHiddenPassword();
};

#endif
