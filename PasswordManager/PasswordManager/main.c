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

	//char* pass = (char*)calloc(50, sizeof(char));
	//char* new_Pass = (char*)calloc(PASSWORD_LENGTH, sizeof(char));

	pPassword pass = (pPassword)malloc(sizeof(pPassword));
	pass->password = (char*)calloc(PASSWORD_LENGTH, sizeof(char));

	switch (input)
	{
	case 1:
		//printf_s("Enter the length for you password:-");
		//scanf_s("%d", &length);

		// Function Call
		printf_s("\n");
		printf_s("Your new generated password: ");
		randomPasswordGeneration();
		printf_s("\n");
			//passwordStrengthChecker(password);
		
			
	case 2:
			//printf_s("Please enter password\n");
			//scanf_s("%c", &password);
			//passwordStrengthChecker(password);

		//char* pass = (char*)calloc(50, sizeof(char));

		printf_s("\nEnter the pass:");
		//scanf_s("%s", pass);
		gets(pass->password);

		//passwordStrengthChecker(pass->password);

			//char pass;
			//int len, i, uppercase, lowercase, digit, specialcase;
			//i = uppercase = lowercase = digit = specialcase = 0;
			//while (1) {
			//	printf_s("\nEnter the pass:");
			//	//scanf_s("%s", pass);
			//	gets(pass);
			//	len = strlen(pass);

			//	if (len < 8) {
			//		printf_s("pass should be 8 character\n");
			//		getch();
			//	}
			//	else
			//		passwordStrengthChecker(pass);
			//		break;
			//	printf("\n");
			//}
	case 3:

		printf_s("Enter New Password:- ");
		gets(pass->password, PASSWORD_LENGTH);
		
		changePassword(pass->password);

		//changePassword();

		break;
	default:
		break;
	}

	return 0;
}
