#include "CategoryDaoDb.h"

static string queryInsert = "INSERT INTO Category (name, type, registeredDate) VALUES ('";

void CategoryDaoDb::saveCategories(vector<Category> categories, StorageManagerDb &dbManager)
{
    for (const auto&category : categories) {
        string query = queryInsert
        + category.getName() + "', " 
        + to_string(static_cast<int>(category.getType())) + ", '"
        + category.getDate() + "');";
        dbManager.executeQuery(query);
    }
}

bool CategoryDaoDb::saveCategory(Category category, StorageManagerDb &dbManager)
{
    string query = queryInsert 
    + category.getName() + "'," 
    + to_string(static_cast<int>(category.getType())) + ", '"
    + category.getDate() + "');";
    return dbManager.executeQuery(query);
}

vector<Category> CategoryDaoDb::loadCategoriesByType(int type, StorageManagerDb &dbManager)
{
    vector<Category> categories;
    sqlite3_stmt* stmt;
    string query = "SELECT id, name, type, registeredDate FROM Category where type = " + to_string(type);
    if (sqlite3_prepare_v2(dbManager.getDb(), query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            
            int id = sqlite3_column_int(stmt, 0);
            string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            int typeValue = sqlite3_column_int(stmt, 2);
            string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
            categories.emplace_back(id, name, static_cast<TransactionType>(typeValue),Date::parseDate(date));
            
        }
        sqlite3_finalize(stmt);
    } else {
        cerr << "Error in query: " << sqlite3_errmsg(dbManager.getDb()) << endl;
        return categories;
    }
    return categories;
}
