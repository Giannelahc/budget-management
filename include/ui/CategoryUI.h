#ifndef CATEGORY_UI_H
#define CATEGORY_UI_H

#include "util/StorageManagerDb.h"

class CategoryUI {
public:
    static void registerCategory(StorageManagerDb& storageManagerDb);
    static void showCategories(StorageManagerDb& storageManagerDb);
};

#endif
