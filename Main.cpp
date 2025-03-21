#include <iostream>
#include "User.h"
#include <ctime>
#include <vector>
#include <string.h>
#include <conio.h>
#include <iomanip>

using namespace std;

void registerUser(FILE *M, User user);
void showUser(FILE *M, User user);


int main() {
    User user;
    FILE M;
    int opc;
    do{
		do{system("cls");
			printf("\n\t******WELCOME USER******\n");
			printf("\t1. Register user\n");
            printf("\t2. Show user\n");
            printf("\t6. Quit\n");
			printf("\tType the option: ");
			cin>>opc;
		}while(opc<1 || opc>6);
		switch(opc){
			case 1:system("cls");
					registerUser(&M,user);
					getch();
					break;
			case 2:	system("cls");
					showUser(&M,user);
					getch();
					break;
			case 3:	system("cls");
					//deudores(&M,&AUX,U);
					getch();
					break;
			case 4:	//gasto(&M,&AUX,U);
					break;
			case 5: system("cls");
					//deposito(&M,&AUX,U);
					break;
			case 6: system("pause");
					break;
		}
	}while(opc!=6);
	
}

void registerUser(FILE *M, User user){
	char name[15];
    double amount;
	printf("\n\t***USER***\n");
	printf("\n\tName: ");
	fflush(stdin);
	gets(name);
	strupr(name);
    user.setName(name);
	//strcpy(N.nom,name);
	fflush(stdin);
	printf("\tAmount: ");
	cin>>amount;
    user.setAmount(amount);
	M=fopen("Usuario.dat","ab+");
	if(M!=NULL)
		fwrite(&user,sizeof(user),1,M);
	else
		printf("No data\n");
	fclose(M);
}

void showUser(FILE *M, User user){
	M=fopen("Usuario.dat","rb");
	if(M!=NULL){
		fread(&user,sizeof(user),1,M);
		printf("\n\t***DATA***\n\n");
		cout<<"\tName: "<<user.getName();
		cout<<"\tAmount: "<<user.getAmount()<<setw(8);	
	}
	else
		printf("No data\n");
	fclose(M);
}