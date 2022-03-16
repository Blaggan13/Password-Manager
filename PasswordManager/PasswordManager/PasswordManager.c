#define _CRT_SECURE_NO_WARNINGS
#include "PasswordManager.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

void loginPage(char* fileName) {
	printf("Good %s!\n", timeOfADay());

	while (1) {
		printf("1. Login\n2. Create an account\n");
		char menu;
		scanf_s(" %c", &menu, 1);

		switch (menu) {
		case '1': login(fileName); break;
		case '2': createNewAccount(fileName); break;
		default: printf("Wrong input. Try again, please\n"); break;
		}
	}
}

void menu(char* startupFile, char* passwordsFile) {
	// The menu should display repeatedly until stopped.
	exit(0);
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