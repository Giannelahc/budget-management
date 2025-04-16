#include "ui/CategoryUI.h"
#include "dao/CategoryDaoDb.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

void CategoryUI::registerCategory(StorageManagerDb& storageManagerDb) {
    string name;
    int type;

    cin.ignore();
    cout << "\n\t***CATEGORY***\n";
    cout << "\n\tName: ";
    //cin.ignore();
    getline(cin, name);
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    printf("\n\tType: ");
	printf("\n\t0. Income\n\t1. Outcome");
	printf("\n\tEnter id type: ");
    cin >> type;

    Category category(name, static_cast<TransactionType>(type));
    CategoryDaoDb categoryDaoDb;
    categoryDaoDb.saveCategory(category, storageManagerDb);

    cout << "\n\tCategory saved.\n";
}

void CategoryUI::showCategories(StorageManagerDb& storageManagerDb) {
    CategoryDaoDb categoryDaoDb;
	vector<Category> categories = categoryDaoDb.loadCategories(storageManagerDb);
	std::cout << std::left << "\t"
              << std::setw(3) << "ID" 
              << std::setw(15) << "Name"
              << std::setw(10) << "Type"
              << std::setw(20) << "Registered Date"
              << std::endl;

    std::cout << "\t" << std::setw(3) << std::setfill('-') << "" 
              << std::setw(15) << "" 
              << std::setw(10) << "" 
              << std::setw(20) << "" 
              << std::endl;

    std::cout << std::setfill(' ');
	for (Category category : categories) {
		category.showCategory();
	}
}
