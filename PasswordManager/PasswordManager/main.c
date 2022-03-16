#include <stdio.h>
#include <stdlib.h>
#include "Password.h"

int main() {
	   
	printf_s("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
	printf_s("|   /$$$$$$$                                                                      /$$       /$$      /$$                                                              |\n");
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
	//printf_s("|          2. Check Password Strength                                                                                                                                 |\n");
	printf_s("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
	
	printf_s("\nEnter your selection:-");
	scanf_s("%d", &input);

	switch (input)
	{
	case 1:
		printf_s("1. Generate Random Password\n");
		printf_s("2. Check Password Strength\n");
		printf_s("3. Change Password\n");
		printf_s("\nEnter your selection:-");
		
		int num;
		int length;
		//char password;
		scanf_s("%d", &num);
	
		switch (num)
		{
		case 1:
			printf_s("Enter the length for you password:-");
			scanf_s("%d", &length);

			// Function Call
			printf_s("\n");
			randomPasswordGeneration(length);
			printf_s("\n");
			//passwordStrengthChecker(password);
			
		case 2:
			printf_s("Please enter password\n");
			//scanf_s("%c", &password);
			//passwordStrengthChecker(password);

			char pass[30];
			int len, i, uppercase, lowercase, digit, specialcase;
			i = uppercase = lowercase = digit = specialcase = 0;
			while (1) {
				printf_s("\n enter the pass:");
				scanf_s("%s", &pass);
				len = strlen(pass);

				if (len < 8) {
					printf("pass should be 8 character");
					getch();
				}
				else
					break;
				printf("\n");
			}

		default:
			break;
		}
	default:
		break;
	}

	return 0;
}
