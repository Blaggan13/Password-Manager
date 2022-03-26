#define _CRT_SECURE_NO_WARNINGS
#include "Application.h"
#include <stdio.h>
#include <stdlib.h>

pApplication createApplication() {
	pApplication app = (pApplication)malloc(sizeof(APPLICATION) * 1);
	if (!app) {
		fprintf(stderr, "Error allocating memory.");
	}

	app->appName = (char*)calloc(APP_NAME_LENGTH, sizeof(char));
	app->username = (char*)calloc(USERNAME_LENGTH, sizeof(char));
	app->password = createPassword();
	app->password->password = (char*)calloc(PASSWORD_LENGTH, sizeof(char));

	return app;
}