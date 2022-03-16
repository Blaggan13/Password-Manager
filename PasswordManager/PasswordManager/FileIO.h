#ifndef FILEIO_H
#define FILEIO_H

#include "Encryption.h"

#include <stdio.h>
#include <stdbool.h>

// This is the constant file name for I/O
#define FILE_NAME "applog.txt"

// This function is designed to write information to file
void writeToFile(pApplication* apps);

// This function is designed to read information from the file
pApplication* readFile();

// This function is designed to read an Application struct from the file
void readApplicationFromFile(FILE* fptr, pApplication app);

// This function is designed to check if the file is empty
bool isFileEmpty(FILE* fptr);

#endif 