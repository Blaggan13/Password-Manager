#pragma once
#include "Application.h"
#include "FileIO.h"

#define WAIT_TIME 3000

// This function will serve as a login page
void loginPage(char* fileName);

// This function is designed to display the console menu of the password manager
void menu(char* startupFile, char* passwordsFile);

// This function enables user to log in using his username & password
void login(char* fileName);

// This function enables user to create new account
void createNewAccount(char* fileName);

// This function returns the current time of a day
char* timeOfADay();