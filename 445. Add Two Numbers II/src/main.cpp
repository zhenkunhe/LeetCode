#include <iostream>
#include <stack>
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
		ListNode* head = nullptr;
		ListNode* cur = nullptr;
		stack<int> s1, s2;
		int sum = 0;
		while (l1)
		{
			s1.push(l1->val);
			l1 = l1->next;
		}
		while (l2)
		{
			s2.push(l2->val);
			l2 = l2->next;
		}
		while (!s1.empty() || !s2.empty())
		{
			sum /= 10;
			if ( !s1.empty() )
			{
				sum += s1.top();
				s1.pop();
			}
			if ( !s2.empty() )
			{
				sum += s2.top();
				s2.pop();
			}
			head = new ListNode(sum % 10);
			head->next = cur;
			cur = head;
		}
		if ( sum >= 10 )
		{
			head = new ListNode(sum / 10);
			head->next = cur;
		}
		return head;
	}
};

int main()
{
	Solution s;
	ListNode* l1 = new ListNode(7);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(4);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	ListNode* res = s.addTwoNumbers(l1, l2);
	while (res)
	{
		cout << res->val << "\t";
		res = res->next;
	}
	return 0;
}
