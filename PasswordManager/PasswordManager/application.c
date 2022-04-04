#include <stdio.h>
#include <stdlib.h>
#include "Application.h"

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

	app->password = createPassword();

	return app;
}

void deleteApp(pApplication app) {
	free(app->appName);
	app->appName = NULL;
	free(app->username);
	app->username = NULL;
	free(app->password);
	app->password->password = NULL;

}

void changeApp(pApplication app, char* appName, char* username, char* password) {
	strncpy(app->appName, appName, NAME_LENGTH);

	strncpy(app->username, username, NAME_LENGTH);

	changePassword(app->password, password);
}