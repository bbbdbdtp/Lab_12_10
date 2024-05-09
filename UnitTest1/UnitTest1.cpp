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
			// ��������� ������ ��� ����������
			Node* root = new Node{ 1,
								   new Node{2, nullptr, nullptr},
								   new Node{3, nullptr, nullptr} };

			// ��������� ������� ��� ��������
			Assert::AreEqual(1, CountNodesAtLevel(root, 0)); // г���� 0 �� 1 ����� (�����)
			Assert::AreEqual(2, CountNodesAtLevel(root, 1)); // г���� 1 �� 2 �����
			Assert::AreEqual(0, CountNodesAtLevel(root, 2)); // г���� 2 �� 0 �����, �� ������ �� �� ������ ����

			// ��������� ���'���, ��� �������� ������ ���'��
			delete root;
		}
	};
}
