#include <stdio.h>
#include <stdlib.h>
#include "Application.h"

int main() {
	printf_s("1. Create App\n");
	printf_s("2. change App\n");
	printf_s("3. Delete App\n");

	int choice;

	printf_s("Enter your selection: ");
	scanf_s("%d", &choice);

	switch (choice)
	{
	case 1:
		createApp();
	case 2:
		changeApp();
	case 3:
		deleteApp();
	default:
		break;
	}
}