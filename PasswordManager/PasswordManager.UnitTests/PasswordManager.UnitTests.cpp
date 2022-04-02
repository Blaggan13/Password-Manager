#define CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include "CppUnitTest.h"
#include "Application.h"

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

		TEST_METHOD(TestMethod1_CheckAppStructure_AppName)
		{
			pApplication app = (pApplication)malloc(sizeof(pApplication));
			
			strcpy(app->appName, "xyz");
			
			char expected = 'xyz';
			char *Actual = app->appName;

			Assert::AreEqual(expected, *Actual);
		}

		TEST_METHOD(TestMethod2_CheckAppStructure_userName)
		{
			pApplication app = (pApplication)malloc(sizeof(pApplication));

			strcpy(app->username, "test");

			char expected = 'test';
			char* Actual = app->username;

			Assert::AreEqual(expected, *Actual);
		}

		TEST_METHOD(TestMethod3_CheckFunctions)
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

		TEST_METHOD(TestMethod1)
		{
		}
	};
}
