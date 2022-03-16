#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "PasswordManager.h"

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