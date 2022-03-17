#pragma

typedef struct Password {
	char* password;
}Password, * pPassword;

// Function to initialize the password structure
pPassword createPassword();

// Function to randomly generate the password
pPassword randomPasswordGeneration();

// FUnction to change the password
void changePassword(pPassword password, int strength);

// Function to check the password strength
int passwordStrengthChecker(pPassword pass);