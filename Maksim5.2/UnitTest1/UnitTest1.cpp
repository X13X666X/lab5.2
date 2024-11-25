#include "pch.h"
#include "CppUnitTest.h"
#include <cmath> 
#include "../loxcpp.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestFindSum)
        {
            double x = 1.0;
            double eps = 0.001;
            int n = 0;
            double S = 0.0;

            FindSum(x, eps, n, S);

            double expected_sum = cos(x);

            Assert::AreEqual(S, expected_sum, 0.01);
        }

        TEST_METHOD(TestGetA)
        {
            double x = 1.0;
            double n = 2;
            double a = 1.0;

            GetA(x, n, a);

            double expected_a = -(x * x) / ((2 * n) * (2 * n - 1));

            Assert::AreEqual(a, expected_a, 0.0001);
        }
    };
}
