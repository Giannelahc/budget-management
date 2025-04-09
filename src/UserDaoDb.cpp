#include "User.h"
#include "Date.h"
#include "UserDaoDb.h"

bool UserDaoDb::saveUser(const User& user, StorageManagerDb &dbManager)
{
    string query = "INSERT INTO User (name, balance, registeredDate) VALUES ('" 
    + user.getName() + "', " 
    + to_string(user.getBalance()) + ", '" 
    + user.getDate() + "');";
    return dbManager.executeQuery(query);
}

bool UserDaoDb::updateUser(const User& user, StorageManagerDb &dbManager)
{
    string query = "UPDATE User set balance = " 
    + to_string(user.getBalance()) 
    + " WHERE id = " 
    + to_string(user.getId()) + " ;";
    return dbManager.executeQuery(query);
}

vector<User> UserDaoDb::getUsers(StorageManagerDb &dbManager)
{
    vector<User> users;
    sqlite3_stmt* stmt;
    string query = "SELECT id, name, balance, registeredDate FROM User;";

    if (sqlite3_prepare_v2(dbManager.getDb(), query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            double balance = sqlite3_column_double(stmt, 2);
            string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
            
            users.emplace_back(id, name, balance, Date::parseDate(date));
            
        }
        sqlite3_finalize(stmt);
    }
    return users;
}
