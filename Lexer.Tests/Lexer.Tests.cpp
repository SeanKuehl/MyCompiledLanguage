#include "pch.h"
#include "CppUnitTest.h"

#include "Source.h"

#include <string>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LexerTests
{
	TEST_CLASS(LexerTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string expected = "x";
			string input = "x";
			string actual = FilterParameter(input);
			Assert::AreEqual(expected, actual);
		}
	};
}
