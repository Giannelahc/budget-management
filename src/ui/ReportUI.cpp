#include "ui/ReportUI.h"
#include "util/StorageManagerDb.h"
#include "dto/MonthlyBalanceDto.h"
#include "service/ReportService.h"
#include <iomanip>
using namespace std;

void ReportUI::showMonthlyBalanceGraph(StorageManagerDb &storageManagerDb)
{
    ReportService reportService;
    vector<MonthlyBalanceDto> balances = reportService.getMonthlyBalance(storageManagerDb);
    const int maxBarWidth = 30;
    double maxValue = 0.0;
    double minValue = 0.0;

    for (const auto& b : balances) {
        if (b.getBalance() > maxValue) maxValue = b.getBalance();
        if (b.getBalance() < minValue) minValue = b.getBalance();
    }

    if (maxValue == 0 && minValue == 0) {
        std::cerr << "Error: It is not possible to show the graphics" << std::endl;
        return;  
    }

    std::cout << "\n\tMONTHLY BALANCE\n\n";

    for (const auto& b : balances) {
        int barLength = 0;

        if (b.getBalance() >= 0) {
            barLength = static_cast<int>((b.getBalance() / maxValue) * maxBarWidth);
        } else {
            barLength = static_cast<int>((b.getBalance() / minValue) * maxBarWidth);
        }

        if (barLength < 0) barLength = 0;  
        if (barLength > maxBarWidth) barLength = maxBarWidth;  

        if (b.getBalance() >= 0) {
            std::cout << "\t" << b.getMonth() << " | "
                      << std::string(barLength, (char)219) 
                      << "  "
                      << std::fixed << std::setprecision(2)
                      << (b.getBalance() >= 0 ? "+" : "") << b.getBalance() << "\n";
        }
        else {
            
            int leftPadding = maxBarWidth - barLength;
            std::cout << "\t" << b.getMonth() << " | "
                      << std::string(leftPadding, ' ')  
                      << std::string(barLength, '-')   
                      << "  "
                      << std::fixed << std::setprecision(2)
                      << (b.getBalance() >= 0 ? "+" : "") << b.getBalance() << "\n";
        }
    }
    
}