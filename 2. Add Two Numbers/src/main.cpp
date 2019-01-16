#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL)
	{
	}
};

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* result = new ListNode(0);
		ListNode* temp = result;
		int carry = 0, sum = 0;

		while (l1 || l2)
		{
			sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
			carry = sum / 10;
			l1 = l1 ? l1->next : NULL;
			l2 = l2 ? l2->next : NULL;

			temp = temp->next = new ListNode(0);
			temp->val = sum % 10;
		}
		if ( carry )
		{
			temp = temp->next = new ListNode(0);
			temp->val = 1;
		}
		return result->next;
	}
};

int main()
{
	Solution s;
	ListNode* l1 = new ListNode(9);

	ListNode* l2 = new ListNode(1);
	l2->next = new ListNode(9);
	l2->next->next = new ListNode(9);
	s.addTwoNumbers(l1, l2);
	return 0;
}
