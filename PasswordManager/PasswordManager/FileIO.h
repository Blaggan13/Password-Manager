#pragma once
#include "Encryption.h"

// This is the constant file name for I/O
#define FILE_NAME ""

// This function is designed to write information to file
void writeToFile(pApplication* apps);

// This function is designed to read information from the file
pApplication* readFile();