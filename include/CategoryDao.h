#include <vector>
#include "Category.h"
class CategoryDao {
    public:
        void saveCategories(vector<Category> categories);
        void saveCategory(Category category);
        vector<Category> loadCategories();
};