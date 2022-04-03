#include <stdio.h>
#include <stdlib.h>
#include "Password.h"
#define PASSWORD_LENGTH 50

int main() {
	   
	printf_s("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
	printf_s("|    /$$$$$$$                                                                      /$$       /$$      /$$                                                              |\n");
	printf_s("|   | $$__  $$                                                                    | $$      | $$$    /$$$                                                             |\n");
	printf_s("|   | $$  \\ $$ /$$$$$$   /$$$$$$$ /$$$$$$$ /$$  /$$  /$$  /$$$$$$   /$$$$$$   /$$$$$$$      | $$$$  /$$$$  /$$$$$$  /$$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$  |\n");
	printf_s("|   | $$$$$$$/|____  $$ /$$_____//$$_____/| $$ | $$ | $$ /$$__  $$ /$$__  $$ /$$__  $$      | $$ $$/$$ $$ |____  $$| $$__  $$ |____  $$ /$$__  $$ /$$__  $$ /$$__  $$ |\n");
	printf_s("|   | $$____/  /$$$$$$$|  $$$$$$|  $$$$$$ | $$ | $$ | $$| $$  \\ $$| $$  \\__/| $$  | $$      | $$  $$$| $$  /$$$$$$$| $$  \\ $$  /$$$$$$$| $$  \\ $$| $$$$$$$$| $$  \\__/ |\n");
	printf_s("|   | $$      /$$__  $$ \\____  $$\\____  $$| $$ | $$ | $$| $$  | $$| $$      | $$  | $$      | $$\  $ | $$ /$$__  $$| $$  | $$ /$$__  $$| $$  | $$| $$_____/| $$        |\n");
    printf_s("|   | $$     |  $$$$$$$ /$$$$$$$//$$$$$$$/|  $$$$$/$$$$/|  $$$$$$/| $$      |  $$$$$$$      | $$ \\/  | $$|  $$$$$$$| $$  | $$|  $$$$$$$|  $$$$$$$|  $$$$$$$| $$       |\n");
	printf_s("|   |__/      \\_______/|_______/|_______/  \\_____/\\___/  \\______/ |__/       \\_______/      |__/     |__/ \\_______/|__/  |__/ \\_______/ \\____  $$ \\_______/|__/       |\n");
	printf_s("|                                                                                                                                       /$$  \ $$                      |\n");
	printf_s("|                                                                                                                                      |  $$$$$$/                     |\n");
	printf_s("|                                                                                                                                       \______/                       |\n");
	printf_s("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

	int input;
	                                                                                                                                                                                
	printf_s("|          1. Create New Password                                                                                                                                     |\n");
	printf_s("|          2. Check Password Strength                                                                                                                                 |\n");
	printf_s("|          3. Change Password                                                                                                                                         |\n");
	printf_s("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
	
	printf_s("\nEnter your selection:-");
	scanf_s("%d", &input);


	pPassword pass = (pPassword)malloc(sizeof(pPassword));
	pass->password = (char*)calloc(PASSWORD_LENGTH, sizeof(char));

	switch (input)
	{
	case 1:
		printf_s("\n");
		printf_s("Your new generated password: ");
		randomPasswordGeneration();
		printf_s("\n");

		
			
	case 2:

		printf_s("\nEnter the pass:");
		gets(pass->password);

		passwordStrengthChecker(pass->password);

	case 3:

		printf_s("Enter New Password:- ");
		gets(pass->password, PASSWORD_LENGTH);
		
		changePassword(pass->password);

		break;
	default:
		break;
	}

	return 0;
}
