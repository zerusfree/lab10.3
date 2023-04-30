#include "pch.h"
#include "CppUnitTest.h"
#include "../Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest103
{
	TEST_CLASS(UnitTest103)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string fileName = "test.txt";
			
			createFile(fileName);
			
			ifstream infile(fileName);
			Assert::IsTrue(infile.good(), L"File not found");

			string line;
			getline(infile, line);

			Assert::AreEqual(line, string("1\t\tLviv\t\tDrohobych"), L"Invalid first line");
			getline(infile, line);

			Assert::AreEqual(line, string("2\t\tDrohobych\t\tBoryslav"), L"Invalid second line");
			getline(infile, line);

			Assert::AreEqual(line, string("3\t\tKyiv\t\tLviv"), L"Invalid third line");
			getline(infile, line);

			Assert::AreEqual(line, string("4\t\tLviv\t\tBoryslav"), L"Invalid fourth line");
			getline(infile, line);

			Assert::AreEqual(line, string("5\t\tBoryslav\t\tKyiv"), L"Invalid fifth line");
			infile.close();
		}
	};
}
