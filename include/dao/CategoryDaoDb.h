#include <vector>
#include "model/Category.h"
#include "util/StorageManagerDb.h"

class CategoryDaoDb {
    public:
        void saveCategories(vector<Category> categories, StorageManagerDb& dbManager);
        bool saveCategory(Category category, StorageManagerDb& dbManager);
        vector<Category> loadCategoriesByType(int type, StorageManagerDb& dbManager);
        vector<Category> loadCategories(StorageManagerDb& dbManager);
};