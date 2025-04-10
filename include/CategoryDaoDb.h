#include <vector>
#include "Category.h"
#include "StorageManagerDb.h"

class CategoryDaoDb {
    public:
        void saveCategories(vector<Category> categories, StorageManagerDb& dbManager);
        bool saveCategory(Category category, StorageManagerDb& dbManager);
        vector<Category> loadCategoriesByType(int type, StorageManagerDb& dbManager);
};