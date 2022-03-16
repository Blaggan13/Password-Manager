#define _CRT_SECURE_NO_WARNINGS

#include "Encryption.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACE_NUMBER 2

char* encrypt(pApplication app) {
	int length = strlen(app->appName) + strlen(app->username) + strlen(app->password->password) + SPACE_NUMBER;
	char* appStr = (char*)calloc(length, sizeof(char));

	if (!appStr) {
		fprintf(stderr, "Error allocating memory\n");
		return NULL;
	}

	strncat(appStr, app->appName, strlen(app->appName));
	appStr[strlen(app->appName)] = '_';
	strncat(appStr, app->username, strlen(app->username));
	appStr[strlen(app->appName) + strlen(app->username) + 1] = '_';
	strncat(appStr, app->password->password, strlen(app->password->password));

	for (int i = strlen(app->appName); i < strlen(appStr); i++) {
		if (appStr[i] != '_') {
			appStr[i] -= 18;
		}
	}

	return appStr;
}

void decrypt(pApplication app) {
	for (int i = 0; i < strlen(app->username); i++) {
		app->username[i] += 18;
	}
	for (int i = 0; i < strlen(app->password->password); i++) {
		app->password->password[i] += 18;
	}

	return app;
}