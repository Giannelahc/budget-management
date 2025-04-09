#include <iostream>
#include "User.h"
#include "Date.h"
#include "Category.h"
#include "CategoryDaoDb.h"
#include "MovementDaoDb.h"
#include "MovementService.h"
#include "StorageManagerDb.h"
#include "UserDaoDb.h"
#include <ctime>
#include <vector>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <fstream>

using namespace std;

void registerUserFile(User user, StorageManagerDb& storageManagerdb);
void registerCategory(StorageManagerDb& storageManagerDb);
void registerMovement(User& user,StorageManagerDb& storageManagerDb);
void showUser(User user, StorageManagerDb& storageManagerDb);
void showCategories(StorageManagerDb& storageManagerDb);
void listMovements(StorageManagerDb& storageManagerDb);
vector<Category> getCategoryListDefault();
void showMenuRegisterUser(User user, StorageManagerDb& storageManagerDb);
void showMenuUserRegistered(User user, StorageManagerDb& storageManagerDb);

int main() {
    User user;
    int opc;

	StorageManagerDb storageManagerdb = StorageManagerDb();
	if (!storageManagerdb.openDatabase("budget.db")) {
        return 1;
    }

	storageManagerdb.createTablesIfNotExists();

	UserDaoDb userDaoDb;
	vector<User> listUser = userDaoDb.getUsers(storageManagerdb);

	if (listUser.size()==0) {
        showMenuRegisterUser(user, storageManagerdb);
    } else {
		user = listUser[0];
        showMenuUserRegistered(user, storageManagerdb);
    }

	storageManagerdb.closeDatabase();
	
}

void showMenuRegisterUser(User user, StorageManagerDb& storageManagerDb) {
	int opc;
	do{
		system("cls");
		printf("\n\t******WELCOME USER******\n");
		printf("\t1. Register user\n");
		printf("\t2. Quit\n");
		printf("\tType the option: ");
		cin>>opc;
	}while(opc<1 || opc>2);
	switch(opc){
		case 1:system("cls");
				registerUserFile(user, storageManagerDb);
				getch();
				break;
		case 2:	system("pause");
				break;
	}
}

void showMenuUserRegistered(User user, StorageManagerDb& storageManagerDb) {
	int opc;
	do{
		do{ system("cls");
			printf("\n\t\tWELCOME: ");
			cout<<user.getName();
			printf("\n\t1. Register transaction\n");
			printf("\t2. Register new category\n");
			printf("\t3. List categories\n");
			printf("\t4. Show balance\n");
			printf("\t5. List movements\n");
			printf("\t6. Quit\n");
			printf("\tType the option: ");
			cin>>opc;
		}while(opc<1 || opc>6);
		switch(opc){
			case 1: system("cls");
					registerMovement(user, storageManagerDb);
					getch();
					break;
			case 2:	system("cls");
					registerCategory(storageManagerDb);
					getch();
					break;
			case 3:	system("cls");
					showCategories(storageManagerDb);
					getch();
					break;
			case 4:	system("cls");
					showUser(user, storageManagerDb);
					getch();
					break;
			case 5: system("cls");
					listMovements(storageManagerDb);
					getch();
					break;
			case 6: system("pause");
					break;
		}
	}while(opc!=6);
}


void registerUserFile(User user, StorageManagerDb& storageManagerdb){
	string name;
    double amount;
	Date date;
	printf("\n\t***USER***\n");
	printf("\n\tName: ");
	cin.ignore();
	getline(cin, name);
	transform(name.begin(), name.end(), name.begin(), ::toupper);
    user.setName(name);
	printf("\tInitial balance: ");
	cin>>amount;
    user.setBalance(amount);
    user.setRegisteredDate(date);

	UserDaoDb userDao;
	userDao.saveUser(user, storageManagerdb);

	vector<Category> defaultCategories = getCategoryListDefault();
	CategoryDaoDb categoryDaoDb;
	categoryDaoDb.saveCategories(defaultCategories, storageManagerdb);

	showMenuUserRegistered(user, storageManagerdb);
}

void showUser(User user, StorageManagerDb& storageManagerDb){
	printf("\n\t***DATA***\n\n");
	cout<<"\tName: "<<user.getName();
	cout<<"\tBalance: "<<user.getBalance()<<setw(8);	
	cout<<"\tRegistered date: "<<user.getDate();
}

void showCategories(StorageManagerDb& storageManagerDb){
	CategoryDaoDb categoryDaoDb;
	vector<Category> categories = categoryDaoDb.loadCategories(storageManagerDb);
	std::cout << std::left
              << std::setw(5) << "ID" 
              << std::setw(15) << "Name"
              << std::setw(10) << "Type"
              << std::setw(20) << "Registered Date"
              << std::endl;

    std::cout << std::setw(5) << std::setfill('-') << "" 
              << std::setw(15) << "" 
              << std::setw(10) << "" 
              << std::setw(20) << "" 
              << std::endl;

    std::cout << std::setfill(' ');
	for (Category category : categories) {
		category.showCategory();
	}
}

void listMovements(StorageManagerDb& storageManagerDb) {
	MovementDaoDb movementDaoDb;
	vector<MovementDto> movements = movementDaoDb.getMovements(storageManagerDb);
	std::cout << std::left
              << std::setw(3) << "ID" 
              << std::setw(20) << "Description"
              << std::setw(10) << "Amount"
              << std::setw(10) << "Type"
              << std::setw(15) << "Category" 
              << std::setw(20) << "Transaction Date" 
              << std::setw(20) << "Registered Date" 
              << std::endl;

    std::cout << std::setw(5) << std::setfill('-') << "" 
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

void registerCategory(StorageManagerDb& storageManagerDb) {
	string name;
	int type;
	TransactionType transactionType;
	printf("\n\t***CATEGORY***\n");
	printf("\n\tName: ");
	cin.ignore();
	getline(cin, name);
	transform(name.begin(), name.end(), name.begin(), ::toupper);
	printf("\n\tType: ");
	printf("\n\t1. Income\n\t2. Outcome");
	cin>>type;
	if(type <=1) {
		transactionType = TransactionType::INCOME;
	} else {
		transactionType = TransactionType::OUTCOME;
	}
	CategoryDaoDb categoryDaoDb;
	categoryDaoDb.saveCategory(Category(name, transactionType), storageManagerDb);
}

void registerMovement(User& user, StorageManagerDb& storageManagerDb) {
	string desc, transactionDate;
	int type;
	double amount;
	int idCat;
	TransactionType transactionType;
	printf("\n\t***TRANSACTION***\n");
	printf("\n\tDescription: ");
	cin.ignore();
	getline(cin, desc);
	transform(desc.begin(), desc.end(), desc.begin(), ::toupper);
	printf("\tAmount: ");
	cin>>amount;
	printf("\n\tType: ");
	printf("\n\t1. Income\n\t2. Outcome");
	printf("\n\tType id: ");
	cin>>type;
	if(type <=1) {
		type = 0;
	} else {
		type = 1;
	}
	CategoryDaoDb categoryDaoDb;
	vector<Category> categories = categoryDaoDb.loadCategoriesByType(type, storageManagerDb);
	printf("\n\tCategory\n\n");
	for (Category category : categories) {
		cout<<"\t"<<category.getId()<<". "<<category.getName()<<"\n";
	}
	printf("\tType id category: ");
	cin>>idCat;
	printf("\n\tTransaction date (dd/MM/yyyy): ");
	cin>>transactionDate;
	MovementService movementService;
	Movement movement = Movement(desc, amount, Date::parseDateFormat2(transactionDate), idCat);
	movementService.calculateNewBalance(user, movement, storageManagerDb, type);
	printf("\n\tRegistered successfully");
}

vector<Category> getCategoryListDefault(){
	return {
		Category("EDUCATION", TransactionType::OUTCOME), Category("TRANSPORTATION", TransactionType::OUTCOME), 
		Category("ENTERTAINMENT", TransactionType::OUTCOME), Category("HOUSING", TransactionType::OUTCOME), 
		Category("FOOD", TransactionType::OUTCOME), Category("HEALTH", TransactionType::OUTCOME),
		Category("DEPOSIT", TransactionType::INCOME), Category("TRANSFER", TransactionType::INCOME)
	};
}