#pragma once
#include <sqlite3.h>
#include <string>
#include <iostream>

class StorageManagerDb {
private:
    sqlite3* db;
public:
    StorageManagerDb();
    ~StorageManagerDb();
    bool openDatabase(const std::string& filename);
    bool tableExists(const std::string& tableName);
    bool createTablesIfNotExists();
    void closeDatabase();
    bool executeQuery(const std::string& query);
    sqlite3* getDb();
};
