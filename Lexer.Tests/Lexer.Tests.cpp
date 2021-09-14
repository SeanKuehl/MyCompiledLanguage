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
			//change it so that the double check comes first
			//and looks for a period in the num, as well as checks for 
			//valid stod conversion
			string expected = "double";
			string input = "10.0";
			string actual = FilterParameter(input);
			Assert::AreEqual(expected, actual);
		}
	};
}
