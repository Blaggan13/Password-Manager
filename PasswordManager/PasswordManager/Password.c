
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "Password.h"
#include <ctype.h >



//#define N 10

// Function to randomly generates password
// of length 
char randomPasswordGeneration(int length)
{
	
	// Initialize counter
	int i = 0;

	int randomizer = 0;

	// Seed the random-number generator
	// with current time so that the
	// numbers will be different every time
	srand((unsigned int)(time(NULL)));

	// Array of numbers
	char numbers[] = "0123456789";

	// Array of small alphabets
	char letter[] = "abcdefghijklmnoqprstuvwyzx";

	// Array of capital alphabets
	char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";

	// Array of all the special symbols
	char symbols[] = "!@#$^&*?";

	// Stores the random password
	//char password[length];
	*password1.password[length];


	// To select the randomizer
	// inside the loop
	randomizer = rand() % 4;

	// Iterate over the range [0, N]
	for (i = 0; i < length; i++) {

		if (randomizer == 1) {
			*password1.password[i] = numbers[rand() % 10];
			randomizer = rand() % 4;
			printf_s("%c", *password1.password[i]);
		}
		else if (randomizer == 2) {
			*password1.password[i] = symbols[rand() % 8];
			randomizer = rand() % 4;
			printf_s("%c", *password1.password[i]);
		}
		else if (randomizer == 3) {
			*password1.password[i] = LETTER[rand() % 26];
			randomizer = rand() % 4;
			printf_s("%c", *password1.password[i]);
		}
		else {
			*password1.password[i] = letter[rand() % 26];
			randomizer = rand() % 4;
			printf_s("%c", *password1.password[i]);
		}
	}

	

	char *pass = *password1.password;

	passwordStrengthChecker(*pass);

	return *pass;
}

char createPassword(char *final_password) {
	*final_password = password1.password;

	return *final_password;
}

//char changePassword(struct Password, password) {
//
//}

void passwordStrengthChecker(pass){
		int *i, uppercase, lowercase, digit, specialcase;
		i = uppercase = lowercase = digit = specialcase = 0;
		for (i = 0; pass[i] != '\0'; i++)
		{
			if (pass[i] >= 65 && pass[i] <= 90)   // check [A-Z] character present or not(UPPERCASE)
				uppercase++;
			else
				if (pass[i] >= 97 && pass[i] <= 122) //check [a-z] character present of not(lowercase)
					lowercase++;
				else
					if (pass[i] >= 48 && pass[i] <= 57) //check[0-9] digit present or not
						digit++;
					else
						specialcase++;
		}

		printf_s("your pass is:");
		if (uppercase > 0 && lowercase > 0 && digit > 0 && specialcase > 0)
			printf_s("Very strong");
		else {
			if (lowercase > 0 && uppercase > 0 && (digit > 0 || specialcase > 0))
				printf_s("strong..");
			else {
				if (lowercase > 0 && (uppercase > 0 || digit > 0 || specialcase > 0))
					printf_s("Medium..");
				else
					if (lowercase > 0 && uppercase == 0 && digit == 0 && specialcase == 0)
						printf_s("weak..");
			}
		}
}
