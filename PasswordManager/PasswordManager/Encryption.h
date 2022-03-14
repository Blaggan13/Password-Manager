#pragma once
#include "Application.h"

// This function is designed to encrypt the username & password
char* encrypt(pApplication app);

// This function is designed to decrypt the username & password
pApplication decrypt(char* str);