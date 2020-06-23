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
void uMenu(int);
void uDep(int);
void vBal(int);
void uDraw(int);

bool maxed = false;

struct Accounts {
	char username[25];
	char password[25];
	float balance;
	int uSSN;
}a[10] = {0};

//User Menu: View Summary, Deposit, Withdraw, Log Out

void cScreen(){
	system("clear");
}

void vBal(int i){
	cScreen();
	printf("%s, your balance is: $%.2f.\n",a[i].username,a[i].balance);
	printf("\n\n");
	
}

void uDraw(int i){
	
	float amt;

	cScreen();

	printf("Enter how much money to withdraw: ");
	scanf("%f",&amt);

	while(a[i].balance - amt < 0){
		printf("Not enough money to withdraw!\n");
		printf("Enter a smaller amount to withdraw: ");
		scanf("%f",&amt);
	}

	a[i].balance = a[i].balance - amt;
}

void uDep(int i){

	float amt;

	cScreen();
	
	printf("Enter how much money to deposit: ");
	scanf("%f",&amt);

	while(amt <= 0){
		printf("There must be some money to deposit!\n");
		printf("Please enter a different amount: ");
		scanf("%f",&amt);
	}

	a[i].balance = a[i].balance + amt;

}

void uMenu(int i){
	
	cScreen();

	int choice;

	while(true){
		printf("Welcome, %s!\n",a[i].username);
		printf("\n");
		printf("1. View Balance\n");
		printf("2. Deposit\n");
		printf("3. Withdraw\n");
		printf("4. Log Out\n");
		printf("\n");
		printf("Option: ");
		scanf("%d",&choice);

		switch(choice){
			
			case 1:
				vBal(i);
				break;
			
			case 2:
				uDep(i);
				break;

			case 3:
				uDraw(i);
				break;

			case 4:
				mMenu();
				break;

			default:
				printf("Invalid choice");
				break;

		}

	}
}

void logIn(){
	
	cScreen();
	char user[MAX];
	char pass[MAX];
	int i;
	
	while(true){
		printf("Username: ");
		scanf("%s",user);
		cScreen();
		printf("Password: ");
		scanf("%s",pass);
		cScreen();
		for(i = 0; i < 10; i++){
			if(strcmp(a[i].username,user) == 0 && strcmp(a[i].password,pass) == 0){
				uMenu(i);
			}
		}
		cScreen();

		printf("Credentials don't match any account!\n");
		continue;
	}
}

void mMenu(){

	cScreen();

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
				logIn();
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
	char uPass[MAX];
	char cPass[MAX];
	int i;
	int SSN;
	bool taken = false;

	printf("Please enter a username: ");
	scanf("%s",uName);

	cScreen();

	for(i = 0; i < 10; i++){
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

		for(i = 0; i < 10; i++){
			if(strcmp(a[i].username,uName) == 0){
				taken = true;
				break;
			}
		}
	}

	for(i = 0; i < 10; i++){
		if(a[i].username[0] == '\0'){
			strcpy(a[i].username, uName);

			while(true){

				printf("Please enter a password at least 8 chars long: ");
				scanf("%s",uPass);

				while(strlen(uPass) < 8){
					printf("Password must be at least 8 characters long.\n");
					printf("Please enter a new password: ");
					scanf("%s",uPass);
				}

				printf("Please confirm password: ");
				scanf("%s",cPass);

				if(strcmp(uPass,cPass) != 0){
					continue;
				}

				strcpy(a[i].password,uPass);
				break;
			}

			while(true){
				printf("Please enter a valid SSN: ");
				scanf("%d",&SSN);

				while(SSN < 111111111 || SSN > 999999999){
					printf("Not a valid SSN! Try a new one: ");
					scanf("%d",&SSN);
				}

				a[i].uSSN = SSN;
				break;
			}

			break;
		}
	}
}

int main(void){
	mMenu();
	return 0;
}
