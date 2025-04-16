#include "service/ReportService.h"
#include "dto/MonthlyBalanceDto.h"
#include "dao/ReportDaoDb.h"

std::vector<MonthlyBalanceDto> ReportService::getMonthlyBalance(StorageManagerDb &db)
{
    ReportDaoDb reportDaoDb;
    return reportDaoDb.getMonthlyBalance(db);
}