#include "pch.h"
#include "CppUnitTest.h"


extern "C" {
#define _CRT_SECURE_NO_WARNINGS
#include "Password.h"
#define PASSWORD_LENGTH 50
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

		TEST_METHOD(TestMethod1)
		{
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
