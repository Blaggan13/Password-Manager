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
			//strcpy(app->username, "test");
			
			char expected = 'xyz';
			char *Actual = app->appName;
			//printf_s("\n%s", app->username);

			Assert::AreEqual(expected, *Actual);
		}

		TEST_METHOD(TestMethod1_CheckFunctions)
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
