#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 25
#define MIN 8

void mMenu();
void aCreate();
void logIn();
void cScreen();
void printUsers();

bool maxed = false;

struct Accounts {
	char username[25];
	char password[25];
	float balance;
	int uSSN;
}a[] = {0};

int accs = sizeof(a)/sizeof(a[0]);

//Main Menu: Create Account, Log In, Exit
//User Menu: View Summary, Deposit, Withdraw, Log Out

void cScreen(){
	system("clear");
}

void mMenu(){

	int choice;
	
	while(true){
		printf("1. Create Account\n");
		printf("2. Log In\n");
		printf("3. Exit\n");

		printf("Option: ");
		scanf("%d",&choice);
		cScreen();

		switch(choice){
			case 1:
				if(maxed == true){
					printf("Accounts maxed! Can't make more.\n");
					break;
				}

				else{
					aCreate();
					break;
				}
		
			case 2:
				printUsers();
				break;

			case 3:
				exit(0);
				break;

			default:
				while(choice < 1 || choice > 3){
					printf("Invalid choice! Try again: ");
					scanf("%d",&choice);
				}
		}
	}
}

void printUsers(){
	for(int i = 0; i < accs; i++){
		char bal[25];
		printf("User %d: %s\n",i,a[i].username);
		sprintf(bal, "%.2f", a[i].balance);
		printf("User %d Balance: %s\n",i,bal);
	}
}

void aCreate(){
	
	char uName[MAX];
	int i;
	bool taken = false;

	printf("Please enter a username: ");
	scanf("%s",uName);

	cScreen();

	for(i = 0; i < accs; i++){
	//Make sure to use strcmp, you homo sapien
		if(strcmp(a[i].username,uName) == 0){
			taken = true;	
		}
	}

	while(taken == true){
		taken = false;
		printf("Username is taken! Try a new one: ");
		scanf("%s",uName);

		cScreen();

		for(i = 0; i < accs; i++){
			if(strcmp(a[i].username,uName) == 0){
				taken = true;
				break;
			}
		}
	}

	for(i = 0; i < accs; i++){
		if(a[i].username[0] == '\0'){
			strcpy(a[i].username, uName);
			break;
		}
	}
}

int main(void){
	mMenu();
	return 0;
}
