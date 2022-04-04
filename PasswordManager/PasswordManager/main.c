#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "PasswordManager.h"

#define PASSWORD_LENGTH 50

//int main() {
	   
/*	printf_s("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
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
		char* newPassword = (char*)calloc(PASSWORD_LENGTH, sizeof(char));
		printf_s("Enter New Password:- ");
		gets(newPassword, PASSWORD_LENGTH);
		
		changePassword(pass->password, newPassword);

		break;
	default:
		break;
	}

=======*/

int main(int argc, char* argv[]) {
	loginPage(argv[1]);

	return 0;
}


/*
	MODULE TEST: IF NEEDED - ctrl + c and ctrl + v to main.

	APPLICATION* app = createApplication();
	pApplication* apps = (pApplication)malloc(2 * sizeof(app));

	*(apps + 0) = createApplication();

	(*(apps + 0))->appName = "application";
	(*(apps + 0))->username = "username";
	(*(apps + 0))->password->password = "password";

	*(apps + 1) = createApplication();

	(*(apps + 1))->appName = "applicationB";
	(*(apps + 1))->username = "usernameB";
	(*(apps + 1))->password->password = "passwordB";


	printf("%d, %d, %d, %d, %d", sizeof(apps), sizeof(*apps), sizeof(apps), strlen(apps), strlen(*apps));
	printf("%s; %s; %s", (*(apps + 0))->appName, (*(apps + 0))->username, (*(apps + 0))->password->password);
	printf("%s; %s; %s", (*(apps + 1))->appName, (*(apps + 1))->username, (*(apps + 1))->password->password);

	writeToFile("applog.txt", apps, 2);
	pApplication* applications = readFile("applog.txt");
*/