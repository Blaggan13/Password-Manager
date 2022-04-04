#ifndef FILEIO_H
#define FILEIO_H

#include "Encryption.h"

#include <stdio.h>
#include <stdbool.h>

// -------------------------------------------------------------------------------------------------------------
// FUNCTIONS FOR KEY PROJECT FUNCTIONALITY

// This function is designed to write information to file
void writeToFile(char* FILE_NAME, pApplication* apps, int count);

// This function is designed to read information from the file
pApplication* readFile(char* FILE_NAME);

// This function is designed to read an Application struct from the file
void readApplicationFromFile(FILE* fptr, pApplication app);


// -------------------------------------------------------------------------------------------------------------
// ACCESS FUNCTIONS (to give acces to app)

// This function checks the login data in order to give access to the app. It returns a filename of a file with passwords if the user really exists and password matches
char* checkUserPass(char* fileName, char* username, char* password);

// This function saves the data of a new user to a text file, but writes the user`s file as appName
void rememberUserPass(char* filename, char* username, char* password);

// -------------------------------------------------------------------------------------------------------------
// SERVICE FUNCTIONS:

// This function is designed to check if the file is empty
bool isFileEmpty(FILE* fptr);

// This function counts a number of lines in a text file
int countLines(FILE* fptr);

#endif 