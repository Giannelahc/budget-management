#include "dao/ReportDaoDb.h"
#include "dao/MovementDaoDb.h"

vector<MonthlyBalanceDto> ReportDaoDb::getMonthlyBalance(StorageManagerDb &dbManager)
{
    std::vector<MonthlyBalanceDto> result;

    const char* sql = R"(
        SELECT 
            SUBSTR(transactionDate, 7, 4) || '-' || SUBSTR(transactionDate, 4, 2) AS month,
            SUM(CASE WHEN type = 0 THEN amount ELSE -amount END) AS balance
        FROM movement m
        INNER JOIN Category c on c.id = m.categoryId
        GROUP BY month
        ORDER BY month DESC;
    )";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(dbManager.getDb(), sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(dbManager.getDb()) << std::endl;
        return result;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string month = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        double balance = sqlite3_column_double(stmt, 1);
        result.emplace_back(month, balance);
    }

    sqlite3_finalize(stmt);
    return result;
}