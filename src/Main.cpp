#include <iostream>
#include "User.h"
#include "Date.h"
#include "Category.h"
#include "CategoryDaoDb.h"
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
void showUser(User user, StorageManagerDb& storageManagerDb);
void showCategories(StorageManagerDb& storageManagerDb);
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
		do{system("cls");
			printf("\n\t\tWELCOME: ");
			cout<<user.getName();
			printf("\n\t1. Register transaction\n");
			printf("\t2. Register new category\n");
			printf("\t3. List categories\n");
			printf("\t4. Show balance\n");
			printf("\t6. Quit\n");
			printf("\tType the option: ");
			cin>>opc;
		}while(opc<1 || opc>6);
		switch(opc){
			case 1:system("cls");
					//registerMovement(user);
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
					//deposito(&M,&AUX,U);
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
	int type;
	printf("\n\tType: ");
	printf("\n\t1. Income\n\t2. Outcome");
	printf("\n\tType the option: ");
	cin.ignore();
	cin>>type;
	if(type <=1) {
		type = 0;
	} else {
		type = 1;
	}
	vector<Category> categories = categoryDaoDb.loadCategoriesByType(type, storageManagerDb);
	system("cls");
	printf("\n\t***CATEGORIES***\n\n");
	for (Category category : categories) {
		cout<<"\t"<<category.getName()<<"\n";
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

vector<Category> getCategoryListDefault(){
	return {
		Category("EDUCATION", TransactionType::OUTCOME), Category("TRANSPORTATION", TransactionType::OUTCOME), 
		Category("ENTERTAINMENT", TransactionType::OUTCOME), Category("HOUSING", TransactionType::OUTCOME), 
		Category("FOOD", TransactionType::OUTCOME), Category("HEALTH", TransactionType::OUTCOME),
		Category("DEPOSIT", TransactionType::INCOME), Category("TRANSFER", TransactionType::INCOME)
	};
}