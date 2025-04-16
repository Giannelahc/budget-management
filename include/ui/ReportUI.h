#ifndef REPORT_UI_H
#define REPORT_UI_H

#include "util/StorageManagerDb.h"

class ReportUI {
public:
    static void showMonthlyBalanceGraph(StorageManagerDb& storageManagerDb);
};

#endif