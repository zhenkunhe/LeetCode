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
	bool hasCycle(ListNode *head)
	{
		map<ListNode*, bool> mappings;
		for (ListNode *i = head; i; i = i->next)
		{
			if ( mappings.count(i) ) return true;
			mappings[i] = true;
		}
		return false;
	}
};

int main()
{
	Solution s;
	ListNode *head = new ListNode(3);
	ListNode *i = head;
	i = i->next = new ListNode(2);
	i = i->next = new ListNode(0);
	i = i->next = new ListNode(-4);
	i->next = head->next;
	s.hasCycle(head);
	return 0;
}
