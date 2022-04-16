#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP 1.4/Matrix.h"
#include "../OOP 1.4/Matrix.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Matrix a;
			a.set_rows(2);
			a.set_cols(2);
			a.create();
			a.set_elem(0, 0, 0.0);
			Assert::AreEqual(0.0, a.get_elem(0, 0));

		}
	};
}
