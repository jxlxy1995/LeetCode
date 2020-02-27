#include <iostream>

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}

		ListNode* firstNode = head;
		ListNode* secondNode = head->next;

		firstNode->next = swapPairs(secondNode->next);
		secondNode->next = firstNode;

		return secondNode;
	}
};

int main()
{
	Solution solution;

	getchar();
	getchar();
	return 0;
}