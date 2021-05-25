#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Student\ Tkachenko.Marharyta.IK11\Lab_6.7\Lab_6.7\6.7.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[6] = { -3, 4, 12, -5, 2, 3 };
			int elem = Min_Element(&a[0], &a[6]);
			Assert::AreEqual(elem, -5);
		}
	};
}