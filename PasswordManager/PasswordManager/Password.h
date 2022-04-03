#pragma once
#define PASSWORD_LENGTH 50

typedef struct Password {
	char* password;
}PASSWORD, * pPassword;

pPassword createPassword();