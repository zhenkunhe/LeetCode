#include <iostream>
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
		ListNode *result = NULL;
		for (; l1 || l2; l1 = l1->next, l2 = l2->next)
		{
		}
		return result;
	}
};

int main()
{
	Solution s;
	ListNode *l1 = new ListNode(1);
	ListNode *i1 = l1;
	i1 = i1->next = new ListNode(2);
	i1 = i1->next = new ListNode(4);

	ListNode *l2 = new ListNode(1);
	ListNode *i2 = l2;
	i2 = i2->next = new ListNode(3);
	i2 = i2->next = new ListNode(4);

	s.mergeTwoLists(l1, l2);
	return 0;
}
