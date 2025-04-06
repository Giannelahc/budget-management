#include "User.h"
#include "Date.h"
#include "UserDaoDb.h"
#include <sstream>

Date parseDate(const std::string& dateString);

bool UserDaoDb::saveUser(const User& user, StorageManagerDb &dbManager)
{
    string query = "INSERT INTO User (name, balance, registeredDate) VALUES ('" 
    + user.getName() + "', " 
    + to_string(user.getBalance()) + ", '" 
    + user.getDate() + "');";
    return dbManager.executeQuery(query);
}

vector<User> UserDaoDb::getUsers(StorageManagerDb &dbManager)
{
    vector<User> users;
    sqlite3_stmt* stmt;
    string query = "SELECT name, balance, registeredDate FROM User;";

    if (sqlite3_prepare_v2(dbManager.getDb(), query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            double balance = sqlite3_column_double(stmt, 1);
            string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            
            users.emplace_back(name, balance, Date::parseDate(date));
            
        }
        sqlite3_finalize(stmt);
    }
    return users;
}
