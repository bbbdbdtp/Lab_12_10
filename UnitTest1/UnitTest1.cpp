#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12_10/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCountNodesAtLevel)
		{
			// Створюємо дерево для тестування
			Node* root = new Node{ 1,
								   new Node{2, nullptr, nullptr},
								   new Node{3, nullptr, nullptr} };

			// Викликаємо функцію для перевірки
			Assert::AreEqual(1, CountNodesAtLevel(root, 0)); // Рівень 0 має 1 вузол (корінь)
			Assert::AreEqual(2, CountNodesAtLevel(root, 1)); // Рівень 1 має 2 вузла
			Assert::AreEqual(0, CountNodesAtLevel(root, 2)); // Рівень 2 має 0 вузлів, бо дерево не має такого рівня

			// Звільняємо пам'ять, щоб уникнути витоку пам'яті
			delete root;
		}
	};
}
