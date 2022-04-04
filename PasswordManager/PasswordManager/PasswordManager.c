#define _CRT_SECURE_NO_WARNINGS
#include "PasswordManager.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

void loginPage(char* fileName) {
	printf("Good %s!\n", timeOfADay());

	while (1) {
		printf("1. Login\n2. Create an account\n3. Exit\n");
		char menu;
		scanf_s(" %c", &menu, 1);

		switch (menu) {
		case '1': login(fileName); break;
		case '2': createNewAccount(fileName); break;
		case '3': exit(1); break;
		default: printf("Wrong input. Try again, please\n"); break;
		}
	}
}

void menu(char* startupFile, char* passwordsFile) {
	pApplication* apps = readFile(passwordsFile);
	int count;
	FILE* fptr;
	fptr = fopen(passwordsFile, "a+");
	if (fptr == NULL) {
		fprintf(stderr, "Error openning %s file!\n", passwordsFile);
		exit(1);
	}
	count = countLines(fptr);
	fclose(fptr);

	while (1) {
		printf("1 - Print all passwords.\n");
		printf("2 - Add new application-password pair.\n");
		printf("3 - Find Password by app name.\n");
		printf("4 - Log out.\n");
		printf("5 - Exit.\n");

		char insert;
		scanf_s(" %c", &insert);

		switch (insert) {
		case '1': {
			printf("|\t\t\tAPP\t\t|\t\tUSERNAME\t\t|\t\tPassword\t\t|\n");
			for (int i = 0; i < count; i++) {
				printf("|\t%25s\t|\t%25s\t|\t%25s\t|\n", (*(apps + i))->appName, (*(apps + i))->username, (*(apps + i))->password->password);
			}
			break;
		}
		case '2': {
			count++;
			apps = (pApplication*)realloc(apps, count * sizeof(pApplication));
			int act = count - 1;
			*(apps + act) = createApp();

			getchar();
			printf("Insert the name of the application you are adding a password for: ");
			gets_s((*(apps + act))->appName, APP_NAME_LENGTH);
			printf("Insert your username in this application: ");
			gets_s((*(apps + act))->username, USERNAME_LENGTH);

			int looper = 1;
			while (looper) {
				printf("1. Do you want to insert your own password?\n2. Or do you want to generate one?\n");
				char in;
				scanf_s(" %c", &in);
				switch (in) {
					case '1': {
						getchar();
						printf("Insert your password: ");
						gets_s((*(apps + act))->password->password, PASSWORD_LENGTH);
						looper = 0;
						break;
					}
					case '2': {
						changePassword((*(apps + act))->password, randomPasswordGeneration()->password);
						printf("Here is your password for this application: %s.\n", (*(apps + act))->password->password);
						looper = 0;
						break;
					}
					default: {
						printf("Wrong input. Please, try again.\n");
						break;
					}
				}
			}
			break;
		}
		case '3': {
			getchar();
			printf("Input name of the app, you want to find: ");
			char* appname = (char*)calloc(APP_NAME_LENGTH, sizeof(char));
			gets_s(appname, APP_NAME_LENGTH);

			printf("|\t\t\tAPP\t\t|\t\tUSERNAME\t\t|\t\tPassword\t\t|\n");

			for (int i = 0; i < count; i++) {
				if (strcmp((*(apps + i))->appName, appname) == 0) {
					printf("|\t%25s\t|\t%25s\t|\t%25s\t|\n", (*(apps + i))->appName, (*(apps + i))->username, (*(apps + i))->password->password);
				}
			}

			break;
		}
		case '4': system("cls"); writeToFile(passwordsFile, apps, count); loginPage(startupFile); break;
		case '5': system("cls"); writeToFile(passwordsFile, apps, count);  printf("Have a great %s!\n", timeOfADay()); exit(0);
		default: printf("Wrong input. Try again!\n"); break;
		}
	}
}

void login(char* fileName) {
	char username[USERNAME_LENGTH];
	char password[PASSWORD_LENGTH];
	getchar();
	printf("Insert your username: ");
	gets_s(username, USERNAME_LENGTH);
	printf("insert your password: ");
	gets_s(password, PASSWORD_LENGTH);

	char* passwordsFile = checkUserPass(fileName, username, password);
	if (passwordsFile) {
		printf("You`ve successfully logged in!\nIn 3 seconds you will be redirected to the dashboard.\n");
		Sleep(WAIT_TIME);
		system("cls");
		menu(fileName, passwordsFile);
	}
	else {
		printf("Wrong username/password!\nYou will be returned to the startup menu in 3 seconds.\n");
		Sleep(WAIT_TIME);
		system("cls");
		return;
	}
}

void createNewAccount(char* fileName) {
	char username[USERNAME_LENGTH];
	char password[PASSWORD_LENGTH];
	getchar();
	printf("Create a username: ");
	gets_s(username, USERNAME_LENGTH);
	printf("Create a password: ");
	gets_s(password, PASSWORD_LENGTH);

	rememberUserPass(fileName, username, password);

	Sleep(WAIT_TIME);
	system("cls");
	strncat(username, ".txt", 4);
	menu(fileName, username);
}

char* timeOfADay() {
	time_t t;
	time(&t);

	char* now = ctime(&t);
	int timeNow = now[11] - '0';
	timeNow *= 10;
	timeNow += now[12] - '0';

	if (timeNow >= 0 && timeNow <= 6) {
		return "night";
	}
	else if (timeNow > 6 && timeNow <= 12) {
		return "morning";
	}
	else if (timeNow > 12 && timeNow <= 18) {
		return "afternoon";
	}
	else if (timeNow > 18 && timeNow <= 24) {
		return "evening";
	}
	return 0;
}