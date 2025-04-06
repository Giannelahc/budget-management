#include "StorageManager.h"
#include "User.h"
#include "UserDao.h"

void UserDao::saveUser(const User& user) {
    std::fstream file = StorageManager::openFile("User.dat", std::ios::out | std::ios::app | std::ios::binary);
    
    if (StorageManager::isFileOpen(file)) {
        StorageManager::writeObject(file, user);
        file.close();
    }
}

void UserDao::loadUser(User& user) {
    std::fstream file = StorageManager::openFile("User.dat", std::ios::in | std::ios::binary);
    
    if (StorageManager::isFileOpen(file)) {
        while (!file.eof()) {
            char type;
            file.read(&type, sizeof(type));
            if (file.eof()) break;

            if (type == 'U') { 
                user.deserialize(file);
            } else {
                file.ignore(1000);
            }
        }
        file.close();
    }
}

