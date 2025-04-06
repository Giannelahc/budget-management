#include "StorageManager.h"
#include "CategoryDao.h"
#include "Category.h"

void CategoryDao::saveCategories(vector<Category> categories){
    std::fstream file = StorageManager::openFile("User.dat", std::ios::out | std::ios::binary);
    
    if (StorageManager::isFileOpen(file)) {
        for (const auto& category : categories) {
            StorageManager::writeObject(file, category);
        }
        file.close();
    }
}

void CategoryDao::saveCategory(Category category){
    std::fstream file = StorageManager::openFile("User.dat", std::ios::out | std::ios::binary);
    
    if (StorageManager::isFileOpen(file)) {
        StorageManager::writeObject(file, category);
        file.close();
    }
}

vector<Category> CategoryDao::loadCategories() {
    vector<Category> categories;
    std::fstream file = StorageManager::openFile("User.dat", std::ios::in | std::ios::binary);
    
    if (StorageManager::isFileOpen(file)) {
        while (!file.eof()) {
            char type;
            file.read(&type, sizeof(type));
            if (file.eof()) break;

            if (type == 'C') { 
                Category category;
                category.deserialize(file);
                categories.push_back(category);
            } else {
                file.ignore(1000);
            }
        }
        file.close();
    }
    return categories;
}
