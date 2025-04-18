#include <vector>
#include "model/User.h"
#include "util/StorageManagerDb.h"

class UserDaoDb {
    public:
        bool saveUser(const User& user, StorageManagerDb& dbManager);
        bool updateUser(const User& user, StorageManagerDb &dbManager);
        vector<User> getUsers(StorageManagerDb& dbManager);
};