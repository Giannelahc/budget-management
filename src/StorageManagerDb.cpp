#include "StorageManagerDb.h"
#include <vector>

StorageManagerDb::StorageManagerDb() : db(nullptr) {}

StorageManagerDb::~StorageManagerDb() {
    closeDatabase();
}

bool StorageManagerDb::openDatabase(const std::string& filename) {
    std::cout <<db;
    int result = sqlite3_open(filename.c_str(), &db);
    std::cout << "sqlite3_open returned: " << result << std::endl;

    if (result == SQLITE_OK) {
        std::cout << "Database opened successfully!\n";
        return true;
    } else {
        std::cout << "Error opening database. Error code: " << result 
                  << ", Message: " << sqlite3_errmsg(db) << std::endl;
    }
    return false;
}

bool StorageManagerDb::tableExists(const std::string& tableName) {
    std::string checkTableQuery = "SELECT name FROM sqlite_master WHERE type='table' AND name='" + tableName + "';";
    sqlite3_stmt* stmt;
    
    if (sqlite3_prepare_v2(db, checkTableQuery.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cout << "Error checking table " << tableName << ": " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    bool exists = (sqlite3_step(stmt) == SQLITE_ROW); // Si devuelve una fila, la tabla existe
    sqlite3_finalize(stmt);  // Liberamos el statement
    return exists;
}

bool StorageManagerDb::createTablesIfNotExists() {
    struct Table {
        std::string name;
        std::string createQuery;
    };

    std::vector<Table> tables = {
        {"User", "CREATE TABLE User (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, balance REAL, registeredDate TEXT);"},
        {"Category", "CREATE TABLE Category (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, registeredDate TEXT);"},
        {"Movement", "CREATE TABLE Movement (id INTEGER PRIMARY KEY AUTOINCREMENT, amount REAL, type TEXT, categoryId INTEGER, registeredDate TEXT, "
                     "transactionDate TEXT, FOREIGN KEY(categoryId) REFERENCES Category(id));"}
    };

    for (const auto& table : tables) {
        if (!tableExists(table.name)) {
            if (sqlite3_exec(db, table.createQuery.c_str(), nullptr, nullptr, nullptr) != SQLITE_OK) {
                std::cout << "Error creating table " << table.name << ": " << sqlite3_errmsg(db) << std::endl;
                return false;
            } else {
                //std::cout << "Table '" << table.name << "' created successfully." << std::endl;
            }
        } else {
            //std::cout << "Table '" << table.name << "' already exists." << std::endl;
        }
    }

    return true;
}

void StorageManagerDb::closeDatabase() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
        //std::cout << "Database closed.\n";
    }
}

bool StorageManagerDb::executeQuery(const std::string& query) {
    char* errorMessage = nullptr;
    if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errorMessage) != SQLITE_OK) {
        std::cerr << "SQL Error: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        return false;
    }
    return true;
}

sqlite3 *StorageManagerDb::getDb()
{
    return db;
}
