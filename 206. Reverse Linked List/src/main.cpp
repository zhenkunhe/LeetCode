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
	ListNode* reverseList(ListNode* head)
	{
		if (!head || !(head->next)) return head;
		ListNode *result = NULL, *node = NULL;
		for (; head; head = head->next)
		{
			node = new ListNode(head->val);
			node->next = result;
			result = node;
		}
		return result;
	}
};

int main()
{
	Solution s;
	ListNode *head = new ListNode(1);
	ListNode *i = head;
	i = i->next = new ListNode(2);
	i = i->next = new ListNode(3);
	i = i->next = new ListNode(4);
	i = i->next = new ListNode(5);
	s.reverseList(head);
	return 0;
}
