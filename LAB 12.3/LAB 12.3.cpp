#include "pch.h"
#include "CppUnitTest.h"
#include "../AP Lab 12.3/AP Lab 12.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LAB123
{
	TEST_CLASS(LAB123)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Node* head = nullptr;
            Node* tail = nullptr;

            Insert(&head, &tail, 1);
            Insert(&head, &tail, 2);
            Insert(&head, &tail, 3);

            Assert::IsNotNull(head);
            Assert::AreEqual(head->data, 1);
            Assert::IsNotNull(head->next);
            Assert::AreEqual(head->next->data, 2);
            Assert::IsNotNull(head->next->next);
            Assert::AreEqual(head->next->next->data, 3);


            Delete(&head, &tail);

		}
	};
}
