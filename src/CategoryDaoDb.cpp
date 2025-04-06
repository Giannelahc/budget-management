#include "CategoryDaoDb.h"

static string queryInsert = "INSERT INTO Category (name, registeredDate) VALUES ('";

void CategoryDaoDb::saveCategories(vector<Category> categories, StorageManagerDb &dbManager)
{
    for (const auto&category : categories) {
        string query = queryInsert
        + category.getName() + "', '" 
        + category.getDate() + "');";
        dbManager.executeQuery(query);
    }
}

bool CategoryDaoDb::saveCategory(Category category, StorageManagerDb &dbManager)
{
    string query = queryInsert 
    + category.getName() + "', '" 
    + category.getDate() + "');";
    bool b = dbManager.executeQuery(query);
    return b;
}

vector<Category> CategoryDaoDb::loadCategories(StorageManagerDb &dbManager)
{
    vector<Category> categories;
    sqlite3_stmt* stmt;
    string query = "SELECT id, name, registeredDate FROM Category;";

    if (sqlite3_prepare_v2(dbManager.getDb(), query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            
            int id = sqlite3_column_int(stmt, 0);
            string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            
            categories.emplace_back(id, name, Date::parseDate(date));
            
        }
        sqlite3_finalize(stmt);
    }
    return categories;
}
