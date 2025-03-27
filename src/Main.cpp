#include <iostream>
#include "User.h"
#include "Date.h"
#include "UserDao.h"
#include <ctime>
#include <vector>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <fstream>

using namespace std;

bool fileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

void registerUserFile(User user);
void showUser(User user);
void showMenuRegisterUser(User user);
void showMenuUserRegistered(User user);

int main() {
    User user;
    int opc;
	
	string filename = "user.dat";
	if (!fileExists(filename)) {
        showMenuRegisterUser(user);
		
    } else {
        showMenuUserRegistered(user);
    }
	
}

void showMenuRegisterUser(User user) {
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
				registerUserFile(user);
				getch();
				break;
		case 2:	system("pause");
				break;
	}
}

void showMenuUserRegistered(User user) {
	int opc;
	do{
		do{system("cls");
			printf("\n\t******WELCOME USER******\n");
			printf("\t1. Register transaction\n");
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
					
					getch();
					break;
			case 3:	system("cls");
					//deudores(&M,&AUX,U);
					getch();
					break;
			case 4:	showUser(user);
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


void registerUserFile(User user){
	string name;
    double amount;
	Date date;
	printf("\n\t***USER***\n");
	printf("\n\tName: ");
	fflush(stdin);
	getline(cin, name);
	transform(name.begin(), name.end(), name.begin(), ::toupper);
    user.setName(name);
	fflush(stdin);
	printf("\tAmount: ");
	cin>>amount;
    user.setBalance(amount);
    user.setRegisteredDate(date);
	UserDao userDao;
	userDao.saveUser(user);
	showMenuUserRegistered(user);
}

void showUser(User user){
	UserDao userDao;
	userDao.loadUser(user);
	printf("\n\t***DATA***\n\n");
	cout<<"\tName: "<<user.getName();
	cout<<"\tAmount: "<<user.getBalance()<<setw(8);	
	cout<<"\tRegistered date: "<<user.getDate();
}