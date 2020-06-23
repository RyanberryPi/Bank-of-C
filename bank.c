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
}a[10] = {0};

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
				printf("Logged in!\n");
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

void aCreate(){
	
	char uName[MAX];
	int i;
	bool taken = false;

	printf("Please enter a username: ");
	scanf("%s",uName);

	for(i = 0; i < 10; i++){
		if(uName == a[i].username){
			taken = true;	
		}
	}

	while(taken == true){
		printf("Username is taken! Try a new one: ");
		scanf("%s",uName);

		for(i = 0; i < 10; i++){
			if(uName == a[i].username){
				taken = true;
				break;
			}

			else if(uName != a[i].username){
				taken = false;
				break;
			}

			else{
				printf("Error during username check. Returning to main menu.\n");
				mMenu();
			}
		}
	}
}

int main(void){
	mMenu();
	return 0;
}
