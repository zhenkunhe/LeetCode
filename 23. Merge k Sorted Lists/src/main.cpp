#include <iostream>
#include <queue>
#include <vector>
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
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		ListNode* result = new ListNode(0);
		ListNode* cur = result;
		priority_queue<int, vector<int>, greater<int> > pq;
		for (auto i : lists)
		{
			while( i )
			{
				pq.push(i->val);
				i=i->next;
			}
		}
		while(!pq.empty())
		{
//			cout << pq.top() << " ";
			cur = cur->next = new ListNode(pq.top());
			pq.pop();
		}

		return result->next;
	}
};

class Solution2
{
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		ListNode* result = new ListNode(0);
		ListNode* cur = result;
		vector<ListNode*> temp = lists;
		while( !temp.empty() )
		{
			ListNode** min = nullptr;
			for (vector<ListNode*>::iterator it = temp.begin(); it != temp.end();)
			{
				if ( !(*it) )
				{
					temp.erase(it);
					continue;
				}
				else
				{
					if ( !min ) min = &(*it);
					else min = (*it)->val < (*min)->val ? &*it : &*min;
					it++;
				}
			}
			if ( min )
			{
//				cout << (*min)->val << " ";
				cur = cur->next = new ListNode((*min)->val);
				*min = (*min)->next;
			}
		}
		return result->next;
	}
};

int main()
{
	Solution s;
	vector<ListNode*> list;
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(5);

	ListNode* l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);

	ListNode* l3 = new ListNode(2);
	l3->next = new ListNode(6);

	list.push_back(l1);
	list.push_back(l2);
	list.push_back(l3);
	s.mergeKLists(list);
	return 0;
}
