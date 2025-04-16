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

    // Encontrar el valor máximo y mínimo
    for (const auto& b : balances) {
        if (b.getBalance() > maxValue) maxValue = b.getBalance();
        if (b.getBalance() < minValue) minValue = b.getBalance();
    }

    // Evitar división por cero si maxValue es 0
    if (maxValue == 0 && minValue == 0) {
        std::cerr << "Error: No se pueden mostrar los gráficos porque todos los balances son 0." << std::endl;
        return;  // Salir de la función si no hay balances válidos
    }

    std::cout << "\n\tBALANCE MONTHLY\n\n";

    // Imprimir cada mes con su barra de gráfico
    for (const auto& b : balances) {
        int barLength = 0;

        if (b.getBalance() >= 0) {
            barLength = static_cast<int>((b.getBalance() / maxValue) * maxBarWidth);
        } else {
            barLength = static_cast<int>((b.getBalance() / minValue) * maxBarWidth);
        }

        if (barLength < 0) barLength = 0;  
        if (barLength > maxBarWidth) barLength = maxBarWidth;  

        // Para balances positivos, usamos el símbolo '█'
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