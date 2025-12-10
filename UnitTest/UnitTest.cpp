#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

// підключаємо файл з функцією
#include "../Lab_05_3/Lab_05_3.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForLab53
{
	TEST_CLASS(UnitTestForLab53)
	{
	public:

		// Тест 1: Перевірка умови |x| < 1 (на прикладі x = 0)
		// Очікуємо: 1/e^0 * (сума перших членів). При x=0 всі члени крім першого = 0.
		// Отже результат має бути 1.0
		TEST_METHOD(TestBranchSmall)
		{
			// Arrange (Підготовка)
			double x = 0.0;
			double expected = 1.0;

			// Act (Дія)
			double actual = k_func(x);

			// Assert (Перевірка)
			// Порівнюємо double з похибкою 0.0001
			Assert::AreEqual(expected, actual, 0.0001, L"Помилка при x = 0");
		}

		// Тест 2: Перевірка умови |x| >= 1 (на прикладі x = 1)
		// Формула: (e^x + sin x) / (cos^2 x + 1)
		TEST_METHOD(TestBranchLarge)
		{
			// Arrange
			double x = 1.0;
			// Рахуємо "еталонне" значення прямо тут стандартними функціями
			double expected = (exp(x) + sin(x)) / (pow(cos(x), 2) + 1);

			// Act
			double actual = k_func(x);

			// Assert
			Assert::AreEqual(expected, actual, 0.0001, L"Помилка при x = 1");
		}

		// Тест 3: Перевірка від'ємного числа |x| >= 1 (на прикладі x = -2)
		TEST_METHOD(TestNegativeLarge)
		{
			// Arrange
			double x = -2.0;
			double expected = (exp(x) + sin(x)) / (pow(cos(x), 2) + 1);

			// Act
			double actual = k_func(x);

			// Assert
			Assert::AreEqual(expected, actual, 0.0001, L"Помилка при x = -2");
		}
	};
}