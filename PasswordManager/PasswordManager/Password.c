#include "Password.h"
#include <stdlib.h>
#include <stdio.h>

pPassword createPassword() {
	pPassword p = (pPassword)malloc(sizeof(PASSWORD) * 1);
	p->password = (char*)calloc(PASSWORD_LENGTH, sizeof(char));
}