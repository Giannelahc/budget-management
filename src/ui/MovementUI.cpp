#include "ui/MovementUI.h"
#include "model/Movement.h"
#include "dto/MovementDto.h"
#include "service/MovementService.h"
#include "dao/CategoryDaoDb.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

void MovementUI::registerMovement(User& user, StorageManagerDb& storageManagerDb) {
    string description, transactionDate;
    double amount;
    int categoryId;
    int type;
    cin.ignore();
    cout << "\n\t***TRANSACTION***\n";
    cout << "\n\tDescription: ";
    getline(cin, description);
    transform(description.begin(), description.end(), description.begin(), ::toupper);
    cout << "\tAmount: ";
    cin >> amount;
    cout << "\tType: ";
    cout << "\n\t1. Income\n\t2. Outcome";
    cout << "\n\tEnter id type: ";
    cin >> type;
    type = type <=1 ? 0 : 1;
    CategoryDaoDb categoryDaoDb;
	vector<Category> categories = categoryDaoDb.loadCategoriesByType(type, storageManagerDb);
	printf("\n\tCategory\n");
	for (Category category : categories) {
		cout<<"\t"<<category.getId()<<". "<<category.getName()<<"\n";
	}
	printf("\tEnter id category: ");
	cin>>categoryId;
	printf("\n\tTransaction date (dd/MM/yyyy): ");
	cin>>transactionDate;

    MovementService movementService;
	Movement movement = Movement(description, amount, Date::parseDateFormat2(transactionDate), categoryId);
	movementService.calculateNewBalance(user, movement, storageManagerDb, type);

    //movementService.registerMovement(movement, storageManagerDb);

    cout << "\n\tTransaction saved.\n";
}

void MovementUI::listMovements(StorageManagerDb& storageManagerDb) {
    MovementService movementService;
    vector<MovementDto> movements = movementService.getAllMovementsWithCategory(storageManagerDb);

    std::cout << std::left <<"\t"
              << std::setw(3) << "ID" 
              << std::setw(20) << "Description"
              << std::setw(10) << "Amount"
              << std::setw(10) << "Type"
              << std::setw(15) << "Category" 
              << std::setw(20) << "Transaction Date" 
              << std::setw(20) << "Registered Date" 
              << std::endl;

    std::cout <<"\t"<< std::setw(5) << std::setfill('-') << "" 
              << std::setw(20) << "" 
              << std::setw(10) << "" 
              << std::setw(10) << "" 
              << std::setw(15) << "" 
              << std::setw(20) << "" 
              << std::setw(20) << "" 
              << std::endl;

    std::cout << std::setfill(' ');
    for(MovementDto movementDto : movements) {
		movementDto.showMovement();
	}
}
