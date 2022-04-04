#pragma once
#include "Password.h"

#define NAME_LENGTH 50

typedef struct Application {
    char* appName;
    char* username;
    pPassword password;
} APPLICATION, *pApplication;

pApplication createApp();

void deleteApp(pApplication app);

void changeApp(pApplication app, char* appName, char* username, char* password);