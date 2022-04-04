#pragma once
#define APP_NAME_LENGTH 50
#define USERNAME_LENGTH 50

#include "Password.h"

typedef struct Application {
	char* appName;
	char* username;
	pPassword password;
} APPLICATION, *pApplication;

pApplication createApplication();