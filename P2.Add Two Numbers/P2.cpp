#include <iostream>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* pRet = new ListNode(0);
		ListNode* pHandler = pRet;
		while (true)
		{
			if (NULL == l1 && NULL == l2)
			{
				break;
			}
			if (NULL == l1)
			{
				l1 = new ListNode(0);
			}
			if (NULL == l2)
			{
				l2 = new ListNode(0);
			}
			int temp = l1->val + l2->val;
			pHandler->val += temp;
			if (NULL != l1->next || NULL != l2->next || pHandler->val >= 10)
			{
				ListNode* pTemp = new ListNode(0);
				pTemp->val += pHandler->val / 10;
				pHandler->val %= 10;
				pHandler->next = pTemp;
				pHandler = pTemp;

				int temp2 = pHandler->val;
				if (temp2 >= 10)
				{
					pHandler->val %= 10;
					pHandler->next = new ListNode(pHandler->val / 10);
					pHandler = pHandler->next;
				}
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		return pRet;
	}
};

int main()
{
	Solution obSolution;
	ListNode* p1 = new ListNode(9);
	ListNode* p2 = new ListNode(1);
	p1->next = new ListNode(9);
	ListNode* p3 = new ListNode(0);
	p3 = obSolution.addTwoNumbers(p1, p2);
	while (p3)
	{
		cout << p3->val << endl;
		p3 = p3->next;
	}
	getchar();
	getchar();
	return 0;
}