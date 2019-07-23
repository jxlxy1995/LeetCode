#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
	void addNext(ListNode* next) { this->next = next; }
};

class Solution {
public:
	ListNode* removeNthFromEnd1(ListNode* head, int n) {
		ListNode *first = NULL, *second = NULL;
		while (head)
		{
			second = head->next;
			head->next = first;
			first = head;
			head = second;
		}

		ListNode* tmp = first;
		ListNode* front = NULL;
		int pos = 1;
		while (tmp)
		{
			if (pos == n) {
				if (front != NULL) {
					front->next = tmp->next;
				}
				else {
					first = tmp->next;
				}

				break;
			}

			front = tmp;
			tmp = tmp->next;
			++pos;
		}

		head = first;
		first = NULL;
		second = NULL;
		while (head)
		{
			second = head->next;
			head->next = first;
			first = head;
			head = second;
		}

		return first;
	}

	ListNode* removeNthFromEnd2(ListNode* head, int n) {
		ListNode *first = head, *second = head;

		int pos = 0;
		int flag = false;
		for (int pos = 0; pos <= n; ++pos) {
			if (first == NULL) {
				flag = true;
				break;
			}

			first = first->next;
		}
		
		if (flag) {
			head = head->next;
		}
		else {
			while (first)
			{
				first = first->next;
				second = second->next;
			}

			second->next = second->next->next;
		}

		return head;
	}

	ListNode* removeNthFromEnd3(ListNode* head, int n) {
		ListNode* first = head;
		while (n-- != 0)
			first = first->next;
		if (!first)
			return head->next;
		ListNode* sec = head;
		while (first->next != NULL) {
			sec = sec->next;
			first = first->next;
		}
		sec->next = sec->next->next;
		return head;
	}
};

void main()
{
	ListNode* testList = new ListNode(1);
	ListNode* tmp = testList;
	for (int i = 2; i < 3; ++i) {
		tmp->addNext(new ListNode(i));
		tmp = tmp->next;
	}

	Solution solution;
	ListNode* ret = solution.removeNthFromEnd2(testList, 1);
	while (ret)
	{
		cout << ret->val << " ";
		ret = ret->next;
	}

	getchar();
	getchar();
}