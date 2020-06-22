#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void mMenu();
void aCreate();
void logIn();
void cScreen();

struct Accounts {
	char _username[25];
	char _password[25];
	float _balance;
	int _SSN;
}a[10] = {0};

//Main Menu: Create Account, Log In, Exit
//User Menu: View Summary, Deposit, Withdraw, Log Out

void cScreen(){
	system("clear");
}

void mMenu(){

	int choice;
	
	cScreen();
	printf("1. Create Account\n");
	printf("2. Log In\n");
	printf("3. Exit\n");

	printf("Option: ");
	scanf("%d",&choice);
	cScreen();

	switch(choice){
		case 1:
			aCreate();
			break;
		
		case 2:
			printf("Logged in!");
			break;

		case 3:
			printf("Exited!");
			break;

		default:
			while(choice < 1 || choice > 3){
				printf("Invalid choice! Try again: ");
				scanf("%d",&choice);
			}
			break;
	}
}

void aCreate(){
	/*
	cScreen();
	char uName[25];
	bool taken = false;

	printf("Please enter a username: ");
	scanf("%s",uName);

	for(int i = 0; i < 10; i++){
		if(uName == a[i]._username){
			taken = true;
		}
	}

	while(taken == true){
		
		taken = false;
		printf("Username is already taken! Please try another: ");
		scanf("%s",uName);

		for(int i = 0; i < 10; i++){

			if(uName == a[i]._username){
				taken = true;
			}
		}
	}
*/
	for(int i = 0; i < 10; i++){
		if(a[i]._username == 0){
			printf("Value is 0 here, boss");
		}
	}

}

int main(void){
	mMenu();
	return 0;
}
