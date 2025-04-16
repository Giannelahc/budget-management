#include "dto/MonthlyBalanceDto.h"
#include "util/StorageManagerDb.h"
#include <vector>

class ReportService {
    public:
        static std::vector<MonthlyBalanceDto> getMonthlyBalance(StorageManagerDb& db);
    };