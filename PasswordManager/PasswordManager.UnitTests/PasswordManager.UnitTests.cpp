#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" {
#define _CRT_SECURE_NO_WARNINGS
#include "Password.h"
#include "Application.h"
#include "Encryption.h"
#include "FileIO.h"
}

namespace PasswordManagerUnitTests
{
	TEST_CLASS(PasswordTests)
	{
	public:
		TEST_METHOD(TestMethod1_PasswordGeneration)
		{
			//Test method to test the random password generation function
			//strlen(randomPasswordGeneration);
			Assert::IsTrue(strlen(randomPasswordGeneration()->password) >= 8);
		}

		TEST_METHOD(TestMethod2_PasswordStrengthChecker)
		{
			//Test method for testing if the password strength checker function works

			pPassword pass = createPassword();

			strcpy_s(pass->password, PASSWORD_LENGTH, "Password@123");

			int expected = 4;

			Assert::AreEqual(expected, passwordStrengthChecker(pass));
		}

		TEST_METHOD(TestMethod3_ChangePasword)
		{
			pPassword pass = createPassword();

			strcpy_s(pass->password, PASSWORD_LENGTH, "Newpass@123");

			char expected[] = "someRaNdOmPaSsWoRd";

			changePassword(pass, expected);

			Assert::AreEqual(expected, pass->password);
		}
	};
	TEST_CLASS(AppllicationTests)
	{
	public:
		TEST_METHOD(TestMethod1_CheckAppStructure)
		{
			pApplication app = createApp();
			
			strcpy_s(app->appName, NAME_LENGTH, "xyz");
			strcpy_s(app->username, NAME_LENGTH, "test");
			changePassword(app->password, "pass");

			Assert::IsTrue(strcmp(app->appName, "xyz") == 0 && strcmp(app->username, "test") == 0 && strcmp(app->password->password, "pass") == 0);
		}
		
		TEST_METHOD(TestMethod2_CheckAppStructure_Password)
		{
			pApplication app = createApp();

			changePassword(app->password, "test");

			Assert::AreEqual("test", app->password->password);
		}

		TEST_METHOD(TestMethod3_CheckFunctions_CreateApp)
		{
			pApplication app = createApp();

			strcpy_s(app->appName, NAME_LENGTH, "xyz");
			strcpy_s(app->username, NAME_LENGTH, "test");
			changePassword(app->password, "pass");
			
			Assert::IsTrue(strcmp(app->appName, "xyz") == 0 && strcmp(app->username, "test") == 0 && strcmp(app->password->password, "pass") == 0);
		}

		TEST_METHOD(TestMethod4_CheckFunctions_deleteApp)
		{
			pApplication app = createApp();

			strcpy_s(app->appName, NAME_LENGTH, "xyz");
			strcpy_s(app->username, NAME_LENGTH, "test");
			changePassword(app->password, "pass");

			deleteApp(app);

			Assert::IsTrue(app->appName == NULL && app->username == NULL && app->password->password == NULL);

		}

		TEST_METHOD(TestMethod5_CheckFunctions_ChangeApp)
		{
			pApplication app = createApp();

			changeApp(app, "Appname", "user", "Password");

			Assert::IsTrue(strcmp(app->appName, "Appname") == 0 && strcmp(app->username, "user") == 0 && strcmp(app->password->password, "Password") == 0);
		}
	};

	TEST_CLASS(EncryptionTests)
	{
	public:

		TEST_METHOD(T001_encrypt_appNameUsernamePassword) {
			// This test case is designed to check if the encrypt() function works properly.
			pApplication app = createApplication();
			app->appName = "appName";
			app->username = "username";
			app->password->password = "password";

			Assert::AreEqual("appName~caS`\\O[S~^Oaae]`R", encrypt(app));
		}
		TEST_METHOD(T002_encrypt_abcDEFghi) {
			// This test case is designed to check if the encrypt() function works properly.
			pApplication app = createApplication();
			app->appName = "abc";
			app->username = "DEF";
			app->password->password = "ghi";

			Assert::AreEqual("abc~234~UVW", encrypt(app));
		}
		TEST_METHOD(T003_encrypt_abcQWErty) {
			// This test case is designed to check if the encrypt() function works properly.
			pApplication app = createApplication();
			app->appName = "abc";
			app->username = "QWE";
			app->password->password = "rty";

			Assert::AreEqual("abc~?E3~`bg", encrypt(app));
		}
		TEST_METHOD(T004_decrypt_appNamecaSOSOaaeR) {
			// This test case is designed to check if the decrypt() function works properly.
			pApplication app = createApplication();
			strcpy_s(app->appName, APP_NAME_LENGTH, "appName");
			strcpy_s(app->username, USERNAME_LENGTH, "caS`");
			strcpy_s(app->password->password, PASSWORD_LENGTH, "^Oaae]`R");

			decrypt(app);

			Assert::IsTrue(strcmp(app->appName, "appName") == 0 && strcmp(app->username, "user") == 0 && strcmp(app->password->password, "password") == 0);
		}
		TEST_METHOD(T005_decrypt_abc234UVW) {
			// This test case is designed to check if the decrypt() function works properly.
			pApplication app = createApplication();
			strcpy_s(app->appName, APP_NAME_LENGTH, "abc");
			strcpy_s(app->username, USERNAME_LENGTH, "234");
			strcpy_s(app->password->password, PASSWORD_LENGTH, "UVW");


			decrypt(app);

			Assert::IsTrue(strcmp(app->appName, "abc") == 0 && strcmp(app->username, "DEF") == 0 && strcmp(app->password->password, "ghi") == 0);
		}
		TEST_METHOD(T006_decrypt_abcE3bg) {
			// This test case is designed to check if the decrypt() function works properly.
			pApplication app = createApplication();
			strcpy_s(app->appName, APP_NAME_LENGTH, "abc");
			strcpy_s(app->username, USERNAME_LENGTH, "?E3");
			strcpy_s(app->password->password, PASSWORD_LENGTH, "`bg");
			
			decrypt(app);

			Assert::IsTrue(strcmp(app->appName, "abc") == 0 && strcmp(app->username, "QWE") == 0 && strcmp(app->password->password, "rty") == 0);
		}
	};
	TEST_CLASS(FileIOTests)
	{
	public:
		
		TEST_METHOD(T001_countLines_aaa_0)
		{
			FILE* fptr;
			fopen_s(&fptr, "C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\aaa.txt", "r");
			int lines = countLines(fptr);
			Assert::AreEqual(0, lines);
			fclose(fptr);
		}
		TEST_METHOD(T002_countLines_loginfo_3)
		{
			FILE* fptr;
			fopen_s(&fptr, "C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\loginfo.txt", "r");
			int lines = countLines(fptr);
			Assert::AreEqual(3, lines);
			fclose(fptr);
		}
		TEST_METHOD(T003_isFileEmpty_aaa_true)
		{
			FILE* fptr;
			fopen_s(&fptr, "C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\aaa.txt", "r");
			Assert::IsTrue(isFileEmpty(fptr));
			fclose(fptr);
		}
		TEST_METHOD(T004_isFileEmpty_loginfo_false)
		{
			FILE* fptr;
			fopen_s(&fptr, "C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\loginfo.txt", "r");
			Assert::IsTrue(!isFileEmpty(fptr));
			fclose(fptr);
		}
		TEST_METHOD(T005_rememberUserPass_checkUserPass)
		{
			char* fileName = "C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\ccc.txt";

			rememberUserPass(fileName, "aaa", "fff");

			Assert::IsTrue(strcmp("aaa.txt", checkUserPass(fileName, "aaa", "fff")) == 0);
		}
		TEST_METHOD(T006_rememberUserPass_checkUserPass)
		{
			char* fileName = "C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\ccc.txt";

			rememberUserPass(fileName, "someUsernameHere", "fff");

			Assert::IsTrue(strcmp("someUsernameHere.txt", checkUserPass(fileName, "someUsernameHere", "fff")) == 0);
		}
		TEST_METHOD(T007_checkUserPass)
		{
			char* fileName = "C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\loginfo.txt";

			Assert::IsTrue(strcmp("abc.txt", checkUserPass(fileName, "abc", "cba")) == 0);
		}
		TEST_METHOD(T008_readApplicationFromFile_AAAbbbCCC)
		{
			FILE* fptr;
			fopen_s(&fptr, "C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\applog.txt", "r");
			pApplication app = createApplication();

			readApplicationFromFile(fptr, app);

			Assert::IsTrue(strcmp("AAA", app->appName) == 0 && strcmp("bbb", app->username) == 0 && strcmp("CCC", app->password->password) == 0);
			fclose(fptr);
		}
		TEST_METHOD(T009_readApplicationFromFile_appUserPass) {
			FILE* fptr;
			fopen_s(&fptr, "C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\textfile.txt", "r");
			pApplication app = createApplication();

			readApplicationFromFile(fptr, app);

			Assert::IsTrue(strcmp("app", app->appName) == 0 && strcmp("User", app->username) == 0 && strcmp("Pass", app->password->password) == 0);
			fclose(fptr);
		}
		TEST_METHOD(T010_writeToFile_readFile) {
			FILE* fptr;
			fopen_s(&fptr, "C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\applog.txt", "r");
			int lines = countLines(fptr) + 1;
			fclose(fptr);

			pApplication* apps = readFile("C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\applog.txt");
			apps = (pApplication*)realloc(apps, (lines * sizeof(pApplication)));
			lines--;
			*(apps + lines) = createApplication();
			strcpy_s((*(apps + lines))->appName, APP_NAME_LENGTH, "appname");
			strcpy_s((*(apps + lines))->username, USERNAME_LENGTH, "username");
			strcpy_s((*(apps + lines))->password->password, PASSWORD_LENGTH, "password");

			writeToFile("C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\applog.txt", apps, lines + 1);

			apps = readFile("C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\applog.txt");

			Assert::IsTrue(strcmp("appname", (*(apps + lines))->appName) == 0 && strcmp("username", (*(apps + lines))->username) == 0 && strcmp("password", (*(apps + lines))->password->password) == 0);
		}
		TEST_METHOD(T011_writeToFile_readFile) {
			FILE* fptr;
			fopen_s(&fptr, "C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\text.txt", "r");
			int lines = countLines(fptr) + 1;
			fclose(fptr);

			pApplication* apps = readFile("C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\text.txt");
			apps = (pApplication*)realloc(apps, (lines * sizeof(pApplication)));
			lines--;
			*(apps + lines) = createApplication();
			strcpy_s((*(apps + lines))->appName, APP_NAME_LENGTH, "someName");
			strcpy_s((*(apps + lines))->username, USERNAME_LENGTH, "USER");
			strcpy_s((*(apps + lines))->password->password, PASSWORD_LENGTH, "PASS");

			writeToFile("C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\text.txt", apps, lines + 1);

			apps = readFile("C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\text.txt");

			Assert::IsTrue(strcmp("someName", (*(apps + lines))->appName) == 0 && strcmp("USER", (*(apps + lines))->username) == 0 && strcmp("PASS", (*(apps + lines))->password->password) == 0);
		}
		TEST_METHOD(T012_writeToFile_readFile) {
			FILE* fptr;
			fopen_s(&fptr, "C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\text.txt", "r");
			int lines = countLines(fptr) + 1;
			fclose(fptr);

			pApplication* apps = readFile("C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\text.txt");
			apps = (pApplication*)realloc(apps, (lines * sizeof(pApplication)));
			lines--;
			*(apps + lines) = createApplication();
			strcpy_s((*(apps + lines))->appName, APP_NAME_LENGTH, "qwertgcx");
			strcpy_s((*(apps + lines))->username, USERNAME_LENGTH, "shvcser");
			strcpy_s((*(apps + lines))->password->password, PASSWORD_LENGTH, "mnbvfghhgfd");

			writeToFile("C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\text.txt", apps, lines + 1);

			apps = readFile("C:\\Users\\armak\\source\\repos\\Team Based Software Development\\PasswordManager\\PasswordManager\\text.txt");

			Assert::IsTrue(strcmp("qwertgcx", (*(apps + lines))->appName) == 0 && strcmp("shvcser", (*(apps + lines))->username) == 0 && strcmp("mnbvfghhgfd", (*(apps + lines))->password->password) == 0);
		}
	};
	TEST_CLASS(PasswordManagerTests)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
		}
	};
}
