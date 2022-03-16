#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FileIO.h"

void writeToFile(pApplication* apps) {
	FILE* fptr;
	fptr = fopen(FILE_NAME, "w");

	if (fptr == NULL) {
		fprintf(stderr, "Error openning %s file!\n", FILE_NAME);
		exit(1);
	}

	int size = sizeof(apps) / sizeof(pApplication);
	fprintf(fptr, "%d\n", size);

	for(int i = 0; i < size; i++) {
		fprintf(fptr, "%s\n", encrypt(*(apps + i)));
	}

	fclose(fptr);
}

pApplication* readFile() {
	pApplication* apps = (pApplication*)malloc(sizeof(pApplication) * 0);
	if (!apps) {
		fprintf(stderr, "Error allocating memory\n");
		exit(1);
	}

	FILE* fptr;
	fptr = fopen(FILE_NAME, "r");
	if (fptr == NULL) {
		fprintf(stderr, "Error openning %s file!\n", FILE_NAME);
		exit(1);
	}

	if (isFileEmpty(fptr)) {
		fclose(fptr);
		return apps;
	}
	else {
		int appsNum;
		fscanf_s(fptr, "%d\n", &appsNum);

		if (appsNum == 0) {
			fclose(fptr);
			return apps;
		}

		for (int i = 0; i < appsNum; i++) {
			apps = (pApplication)realloc(apps, (sizeof(APPLICATION) * (i + 1)));
			if (!apps) {
				fprintf(stderr, "Error reallocating memory\n");
				return NULL;
			}

			*(apps + i) = createApplication();
			readApplicationFromFile(fptr, *(apps + i));
		}
		fclose(fptr);
		return apps;
	}

	fclose(fptr);
	return apps;
}

void readApplicationFromFile(FILE* fptr, pApplication app) {
	fscanf_s(fptr, "\n%[^_]s", app->appName, APP_NAME_LENGTH);
	fscanf_s(fptr, "_%[^_]s", app->username, USERNAME_LENGTH);
	fscanf_s(fptr, "_%[^\n]s", app->password->password, PASSWORD_LENGTH);

	decrypt(app);

	return;
}

bool isFileEmpty(FILE* fptr) {
	if (fptr != NULL) {
		fseek(fptr, 0, SEEK_END);
		int size = ftell(fptr);

		if (size == 0) {
			fseek(fptr, 0, SEEK_SET);
			return true;
		}
		else {
			fseek(fptr, 0, SEEK_SET);
			return false;
		}
	}
}