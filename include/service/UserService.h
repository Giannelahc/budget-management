#include "model/User.h"
#include "util/StorageManagerDb.h"

class UserService {
    public:
        static void registerUser(User& user, StorageManagerDb &dbManager);
        static string hashPassword(const std::string& password);
    };