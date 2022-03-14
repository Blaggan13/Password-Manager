#pragma once
#include "Password.h"

typedef struct Application {
	char* appName;
	char* username;
	pPassword password;
} APPLICATION, *pApplication;