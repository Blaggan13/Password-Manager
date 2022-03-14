#include <stdio.h>
#include <stdlib.h>
#include "Password.h"

int main() {
	   
	printf_s("_____                                     _   __  __\n");
	printf_s("| __ \                                   | | |  \/  |\n");
	printf_s("||__) |_  _ ___ _____      _____  _ __ __| | | \  / | __ _ _ __   __ _  __ _  ___ _ __ \n");
	printf_s("|  ___/ _` / __/ __\ \ /\ / / _ \| '__/ _` | | |\/| |/ _` | '_ \ / _` |/ _` |/ _ \ '__| \n");
	printf_s("| |  | (_| \__ \__ \\ V  V / (_) | | | (_| | | |  | | (_| | | | | (_| | (_| |  __/ |    \n");
	printf_s("|_|   \__,_|___/___/ \_/\_/ \___/|_|  \__,_| |_|  |_|\__,_|_| |_|\__,_|\__, |\___|_|    \n");
    printf_s("                                                                  __/ |           \n");
	printf_s("                                                                 |___/            \n");

	int length;

	printf_s("1.Enter the length for your password:-\n");
	scanf_s("%d", &length);
	
	// Function Call
	randomPasswordGeneration(length);

	return 0;
}
