#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include "Application.h"

// This function is designed to encrypt the username & password
char* encrypt(pApplication app);

// This function is designed to decrypt the username & password
void decrypt(pApplication app);

#endif // !ENCRYPTION_H