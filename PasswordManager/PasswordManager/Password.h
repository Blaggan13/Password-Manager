#pragma

struct Password {
	char* password[];
};
struct Password password1, new_password;

char randomPasswordGeneration(int length);
char createPassword(char *password);
//char changePassword(struct Password);
void passwordStrengthChecker(password);