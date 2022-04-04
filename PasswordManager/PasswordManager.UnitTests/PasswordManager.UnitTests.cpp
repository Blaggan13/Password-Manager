#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" {
#include "Password.h"
#include "Application.h"
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