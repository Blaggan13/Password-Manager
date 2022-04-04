
#pragma once

typedef struct Application {
    char* appName;
    char* username;
    pPassword password;
} APPLICATION, *pApplication;

pApplication createApp();

void deleteApp(pApplication app);

void changeApp(pApplication app);