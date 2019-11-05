#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1 && !l2)
			return NULL;

		ListNode* tmp1 = l1;
		ListNode* tmp2 = l2;
		int firstVal;
		if (!tmp1) {
			return l2;
		}
		else if (!tmp2) {
			return l1;
		}
		else if (tmp1->val < tmp2->val) {
			firstVal = tmp1->val;
			tmp1 = tmp1->next;
		}
		else {
			firstVal = tmp2->val;
			tmp2 = tmp2->next;
		}

		ListNode* ret = new ListNode(firstVal);
		ListNode* head = ret;

		while (tmp1 || tmp2)
		{
			if (!tmp1) {
				firstVal = tmp2->val;
				tmp2 = tmp2->next;
			}
			else if (!tmp2) {
				firstVal = tmp1->val;
				tmp1 = tmp1->next;
			}
			else if (tmp1->val < tmp2->val) {
				firstVal = tmp1->val;
				tmp1 = tmp1->next;
			}
			else {
				firstVal = tmp2->val;
				tmp2 = tmp2->next;
			}

			ListNode* tmpNode = new ListNode(firstVal);
			ret->next = tmpNode;
			ret = ret->next;
		}

		return head;
	}
};

int main()
{
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(4);

	ListNode* l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);

	Solution solution;
	ListNode* l3 = solution.mergeTwoLists(l1, l2);

	ListNode* tmp = l3;
	while (tmp)
	{
		cout << tmp->val << ",";
		tmp = tmp->next;
	}
	cout << endl;

	getchar();
	getchar();
	return 0;
}