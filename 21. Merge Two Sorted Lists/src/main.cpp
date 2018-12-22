#include <iostream>
#include <limits.h>
#include <map>
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode result(INT_MIN);
		ListNode *tail = &result;
		ListNode **choose;

		while (l1 && l2)
		{
			choose = (l1->val <= l2->val) ? &l1 : &l2;
			tail = tail->next = *choose;
			*choose = (*choose)->next;
		}
		tail->next = l1 ? l1 : l2;

		return result.next;
	}
};

int main()
{
	Solution s;
	ListNode *l1 = new ListNode(1);
	ListNode *i1 = l1;
	i1 = i1->next = new ListNode(2);
	i1 = i1->next = new ListNode(4);

	ListNode *l2 = new ListNode(2);
	ListNode *i2 = l2;
	i2 = i2->next = new ListNode(3);
	i2 = i2->next = new ListNode(4);

	ListNode* result = s.mergeTwoLists(l1, l2);

	while (result)
	{
		cout << result->val << endl;
		result = result->next;
	}
	return 0;
}
