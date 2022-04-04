#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#define _CRT_SECURE_NO_WARNINGS
#include "Application.h"
#include "Password.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PasswordManagerUnitTests
{
	TEST_CLASS(PasswordTests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
		}
	};
	TEST_CLASS(AppllicationTests)
	{
	public:
		TEST_METHOD(TestMethod1_CheckAppStructure)
		{
			pApplication app = (pApplication)malloc(sizeof(pApplication));
			
			strcpy_s(app->username, LENGTH, "test");
			strcpy_s(app->password, LENGTH, "pass");

			Assert::IsTrue(strcmp(app->appName, "xyz") == 0 && strcmp(app->username, "test") == 0 && strcmp(app->password->password, "pass") == 0);
		}

		TEST_METHOD(TestMethod2_CheckAppStructure_Password)
		{
			pApplication app = (pApplication)malloc(sizeof(pApplication));

			strcpy_s(app->password, LENGTH, "test");

			char expected = 'test';
			char* Actual = app->password;

			Assert::AreEqual(expected, *Actual);
		}

		TEST_METHOD(TestMethod3_CheckFunctions_CreateApp)
		{
			pApplication app = (pApplication)malloc(sizeof(pApplication));

			strcpy_s(app->appName, LENGTH, "xyz");
			strcpy_s(app->username, LENGTH, "test");
			strcpy_s(app->password, LENGTH, "pass");

			createApp();
			
			Assert::IsTrue(strcmp(app->appName, "xyz") == 0 && strcmp(app->username, "test") == 0 && strcmp(app->password->password, "pass") == 0);

		}

		TEST_METHOD(TestMethod3_CheckFunctions_deleteApp)
		{
			pApplication app = (pApplication)malloc(sizeof(pApplication));

			strcpy_s(app->appName, LENGTH, "xyz");
			strcpy_s(app->username, LENGTH, "test");
			strcpy_s(app->password, LENGTH, "pass");;

			deleteApp(app);

			Assert::IsTrue(strcmp(app->appName, "") == 0 && strcmp(app->username, "") == 0 && strcmp(app->password->password, "") == 0);

		}

		TEST_METHOD(TestMethod3_CheckFunctions_ChangeApp)
		{
			pApplication app = (pApplication)malloc(sizeof(pApplication));

			strcpy_s(app->appName, LENGTH, "Appname");
			strcpy_s(app->username, LENGTH, "user");
			strcpy_s(app->password, LENGTH, "Password");;

			changeApp(app);

			Assert::IsTrue(strcmp(app->appName, "Appname") == 0 && strcmp(app->username, "user") == 0 && strcmp(app->password->password, "Password") == 0);
		}
	};
	TEST_CLASS(EncryptionTests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
		}
	};
	TEST_CLASS(FileIOTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		}
	};
	TEST_CLASS(PasswordManagerTests)
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

			pPassword pass = (pPassword)malloc(sizeof(pPassword));

			strcpy_s(pass->password, PASSWORD_LENGTH, "Password@123");

			int expected = 4;

			Assert::AreEqual(expected, passwordStrengthChecker(pass));
		}

		TEST_METHOD(TestMethod3_ChangePasword)
		{
			pPassword pass = (pPassword)malloc(sizeof(pPassword));

			strcpy_s(pass->password, PASSWORD_LENGTH, "Newpass@123");
			
			char expected[] = "Newpass@123";

			//Assert::AreEqual(expected, changePassword(pass));
		}
	};
}
