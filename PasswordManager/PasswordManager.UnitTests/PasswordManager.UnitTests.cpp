#include "pch.h"
#include "CppUnitTest.h"
#include "Application.h"

#define _CRT_SECURE_NO_WARNINGS

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
			
			strcpy(app->appName, "xyz");
			strcpy(app->username, "test");
			strcpy(app->password, "pass");

			Assert::IsTrue(strcmp(app->appName, "xyz") == 0 && strcmp(app->username, "test") == 0 && strcmp(app->password->password, "pass") == 0);
		}

		TEST_METHOD(TestMethod2_CheckAppStructure_Password)
		{
			pApplication app = (pApplication)malloc(sizeof(pApplication));

			strcpy(app->password, "test");

			char expected = 'test';
			char* Actual = app->password;

			Assert::AreEqual(expected, *Actual);
		}

		TEST_METHOD(TestMethod3_CheckFunctions_CreateApp)
		{
			pApplication app = (pApplication)malloc(sizeof(pApplication));

			strcpy(app->appName, "xyz");
			strcpy(app->username, "test");
			strcpy(app->password->password, "pass");

			createApp();
			
			Assert::IsTrue(strcmp(app->appName, "xyz") == 0 && strcmp(app->username, "test") == 0 && strcmp(app->password->password, "pass") == 0);

		}

		TEST_METHOD(TestMethod3_CheckFunctions_deleteApp)
		{
			pApplication app = (pApplication)malloc(sizeof(pApplication));

			strcpy(app->appName, "xyz");
			strcpy(app->username, "test");
			strcpy(app->password, "pass");;

			deleteApp(app);

			Assert::IsTrue(strcmp(app->appName, "") == 0 && strcmp(app->username, "") == 0 && strcmp(app->password->password, "") == 0);

		}

		TEST_METHOD(TestMethod3_CheckFunctions_ChangeApp)
		{
			pApplication app = (pApplication)malloc(sizeof(pApplication));

			strcpy(app->appName, "Appname");
			strcpy(app->username, "user");
			strcpy(app->password, "Password");;

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

		TEST_METHOD(TestMethod1)
		{
		}
	};
}
