#include "StorageManager.h"
#include "CategoryDao.h"
#include "Category.h"

void CategoryDao::saveCategories(vector<Category> categories){
    std::fstream file = StorageManager::openFile("User.dat", std::ios::out | std::ios::app | std::ios::binary);
    
    if (StorageManager::isFileOpen(file)) {
        for (const auto& category : categories) {
            StorageManager::writeObject(file, categories);
        }
        file.close();
    }
}

void CategoryDao::saveCategory(Category category){

}

vector<Category> CategoryDao::loadCategories()
{
    return vector<Category>();
}
