#include "service/UserService.h"
#include "dao/UserDaoDb.h"
#include <openssl/sha.h>
#include <string>
#include <sstream>
#include <iomanip>

void UserService::registerUser(User &user, StorageManagerDb &dbManager)
{
    user.setPassword(hashPassword(user.getPassword()));
    UserDaoDb userDaoDb;
    userDaoDb.saveUser(user, dbManager);
}

string UserService::hashPassword(const std::string &password)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(password.c_str()), password.size(), hash);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];

    return ss.str();
}
