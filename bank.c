#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void mMenu();
void aCreate();
void logIn();
void cScreen();

struct ACCOUNTS {
	char _username[25];
	char _password[25];
	float _balance;
	int _SSN;
}acc[10] = {0};

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
	
	char uName[25];

	printf("Please enter a username: ");
	
	while(true){
	
		printf("Yeet");

	}

}

int main(void){
	mMenu();
	return 0;
}
