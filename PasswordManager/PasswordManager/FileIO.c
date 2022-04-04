#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "FileIO.h"

void writeToFile(char* FILE_NAME, pApplication* apps, int count) {
	FILE* fptr;
	fptr = fopen(FILE_NAME, "w");

	if (fptr == NULL) {
		fprintf(stderr, "Error openning %s file!\n", FILE_NAME);
		exit(1);
	}

	for (int i = 0; i < count; i++) {
		fprintf(fptr, "%s\n", encrypt(*(apps + i)));
	}

	fclose(fptr);
}

pApplication* readFile(char* FILE_NAME) {
	pApplication* apps = (pApplication*)malloc(sizeof(pApplication) * 0);
	if (!apps) {
		fprintf(stderr, "Error allocating memory\n");
		exit(1);
	}

	FILE* fptr;
	fptr = fopen(FILE_NAME, "r");
	if (fptr == NULL) {
		if (fptr = NULL) {
			fprintf(stderr, "Error openning %s file!\n", FILE_NAME);
			exit(1);
		}
	}

	if (isFileEmpty(fptr)) {
		fclose(fptr);
		return apps;
	}
	else {
		int appsNum = countLines(fptr);

		if (appsNum == 0) {
			fclose(fptr);
			return apps;
		}

		apps = (pApplication)realloc(apps, (sizeof(APPLICATION) * appsNum));
		if (!apps) {
			fprintf(stderr, "Error reallocating memory\n");
			return NULL;
		}

		for (int i = 0; i < appsNum; i++) {
			*(apps + i) = createApp();
			readApplicationFromFile(fptr, *(apps + i));
		}
		fclose(fptr);
		return apps;
	}

	fclose(fptr);
	return apps;
}

void readApplicationFromFile(FILE* fptr, pApplication app) {
	fscanf_s(fptr, "\n%[^~]s", app->appName, APP_NAME_LENGTH);
	fscanf_s(fptr, "~%[^~]s", app->username, USERNAME_LENGTH);
	fscanf_s(fptr, "~%[^\n]s", app->password->password, PASSWORD_LENGTH);

	decrypt(app);

	return;
}

char* checkUserPass(char* fileName, char* username, char* password) {
	pApplication* applications = readFile(fileName);

	int count;
	FILE* fptr;
	fptr = fopen(fileName, "r");
	if (fptr == NULL) {
		fprintf(stderr, "Error openning %s file!\n", fileName);
		exit(1);
	}
	count = countLines(fptr);
	fclose(fptr);

	if (count == 0) {
		return NULL;
	}

	for (int i = 0; i < count; i++) {
		if (strcmp(username, (*(applications + i))->username) == 0 && strcmp(password, (*(applications + i))->password->password) == 0) {
			return (*(applications + i))->appName;
		}
	}
	return NULL;
}

void rememberUserPass(char* filename, char* username, char* password) {
	pApplication* applications = readFile(filename);

	int count;
	FILE* fptr;
	fptr = fopen(filename, "r");
	if (fptr == NULL) {
		fprintf(stderr, "Error openning %s file!\n", filename);
		exit(1);
	}
	count = countLines(fptr);
	fclose(fptr);
	
	count++;
	applications = (pApplication*)realloc(applications, sizeof(pApplication) * count);

	int n = count - 1;
	*(applications + n) = createApp();

	strcpy_s((*(applications + n))->appName, APP_NAME_LENGTH, username);
	strncat((*(applications + n))->appName, ".txt", 4);
	strcpy_s((*(applications + n))->username, USERNAME_LENGTH, username);
	strcpy_s((*(applications + n))->password->password, PASSWORD_LENGTH, password);

	writeToFile(filename, applications, count);

	printf("Account successfully created!\nIn 3 seconds you will be redirected to the dashboard.\n");
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

int countLines(FILE* fptr) {
	char ch;
	int lines = 0;
	while (!feof(fptr))
	{
		ch = fgetc(fptr);
		if (ch == '\n')
		{
			lines++;
		}
	}
	fseek(fptr, 0, SEEK_SET);
	return lines;
}