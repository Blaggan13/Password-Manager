#pragma once

#define PASSWORD_LENGTH 50

typedef struct Password {
	char* password;
}Password, *pPassword;

// Function to initialize the password structure
pPassword createPassword();

// Function to randomly generate the password
pPassword randomPasswordGeneration();

// FUnction to change the password
void changePassword(pPassword pass, char* newPassword);

// Function to check the password strength
int passwordStrengthChecker(pPassword pass);