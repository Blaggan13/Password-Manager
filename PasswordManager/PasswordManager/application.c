#include <stdio.h>
#include <stdlib.h>
#include "Application.h"

#define NAME_LENGTH 25

pApplication createApp() {

	pApplication app = (pApplication)malloc(sizeof(pApplication));
	if (!app) {
		fprintf(stderr, "Error allocating memory");
		exit(-1);
	}

	app->username = (char*)calloc(NAME_LENGTH, sizeof(char));
	if (!app->username) {
		fprintf(stderr, "Error allocating memory");
		exit(-1);
	}

	app->appName = (char*)calloc(NAME_LENGTH, sizeof(char));
	if (!app->appName) {
		fprintf(stderr, "Error allocating memory");
		exit(-1);
	}

	app->password = (char*)calloc(NAME_LENGTH, sizeof(char));
	if (!app->password) {
		fprintf(stderr, "Error allocating memory");
		exit(-1);
	}

	return app->appName, app->username, app->password;
}

void deleteApp(pApplication app) {

	free(app->appName);
	free(app->username);
	free(app->password);

}

void changeApp(pApplication app) {


	//Changing the APP Name
	char* newAppName = (char*)calloc(NAME_LENGTH, sizeof(char));

	scanf_s("%[^\n]s", newAppName, NAME_LENGTH);
	strncpy(app->appName, newAppName, NAME_LENGTH);

	//Changing the username
	char* newUserName = (char*)calloc(NAME_LENGTH, sizeof(char));

	scanf_s("%[^\n]s", newUserName, NAME_LENGTH);
	strncpy(app->username, newUserName, NAME_LENGTH);

	//changing the password
	char* newPassword = (char*)calloc(NAME_LENGTH, sizeof(char));

	scanf_s("%[^\n]s", newPassword, NAME_LENGTH);
	strncpy(app->password, newPassword, NAME_LENGTH);

	//Printing the changes
	printf_s(" New app name: %s", newAppName);
	printf_s(" New username: %s", newUserName);
	printf_s(" New password: %s", newPassword);


}