#include <vector>
#include "model/Movement.h"
#include "dto/MonthlyBalanceDto.h"
#include "util/StorageManagerDb.h"

class ReportDaoDb {
    public:
        vector<MonthlyBalanceDto> getMonthlyBalance(StorageManagerDb& dbManager);
};