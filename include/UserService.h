#include "User.h"
#include "StorageManagerDb.h"

class UserService {
    public:
        static void registerUser(User& user, StorageManagerDb &dbManager);
        static string hashPassword(const std::string& password);
    };