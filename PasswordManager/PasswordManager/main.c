#include <stdio.h>
#include <stdlib.h>
#include "PasswordManager.h"

int main() {
	menu();

	return 0;
}


/*
	MODULE TEST: IF NEEDED - ctrl + c and ctrl + v to main.

	pApplication* apps = (pApplication*)malloc(sizeof(pApplication));

	*(apps + 0) = createApplication();

	(*(apps + 0))->appName = "application";
	(*(apps + 0))->username = "username";
	(*(apps + 0))->password->password = "password";

	writeToFile(apps);
	pApplication* applications = readFile();

	printf("%s; %s; %s", (*(applications + 0))->appName, (*(applications + 0))->username, (*(applications + 0))->password->password);
*/