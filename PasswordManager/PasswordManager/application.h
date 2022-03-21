
#pragma once

typedef struct Application {
    char* appName;
    char* username;
    pPassword password;
} APPLICATION, * pApplication;

pApplication createApp();

void deleteApp();

void changeApp();