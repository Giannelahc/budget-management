#include "util/Date.h"
#include "dao/MovementDaoDb.h"
#include "dao/CategoryDaoDb.h"

bool MovementDaoDb::saveMovement(const Movement &movement, StorageManagerDb &dbManager)
{
    string query = "INSERT INTO Movement (description, amount, categoryId, transactionDate, registeredDate) VALUES ('" 
    + movement.getDescription() + "', " 
    + to_string(movement.getAmount()) + ", " 
    + to_string(movement.getIdCategory()) + ", '" 
    + movement.getTransactionDate() + "', '" 
    + movement.getDate() + "');";
    return dbManager.executeQuery(query);
}

vector<MovementDto> MovementDaoDb::getMovements(StorageManagerDb &dbManager)
{
    vector<MovementDto> movements;
    sqlite3_stmt* stmt;
    string query = "SELECT m.id, description, amount,c.id, name, type, transactionDate, m.registeredDate FROM Movement m INNER JOIN Category c on c.id = m.categoryId";
    if (sqlite3_prepare_v2(dbManager.getDb(), query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            string desc = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            double amount = sqlite3_column_double(stmt, 2);
            int categoryId = sqlite3_column_int(stmt, 3);
            string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
            int type = sqlite3_column_int(stmt, 5);
            string transactionDate = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
            string registeredDate = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
            movements.emplace_back(id, desc, amount, categoryId, name, static_cast<TransactionType>(type), Date::parseDate(transactionDate), Date::parseDate(registeredDate));
            
        }
        sqlite3_finalize(stmt);
    } else {
        cerr << "Error in query: " << sqlite3_errmsg(dbManager.getDb()) << endl;
    }
    return movements;
}
