#include <iostream>
#include <queue>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	int maxDepth(Node *root)
	{
		if ( !root ) return 0;
		priority_queue<int> q;
		for (auto child : root->children)
			q.push(maxDepth(child));
		return q.empty() ? 1 : q.top() + 1;
	}
};

int main()
{
	Solution s;
	Node *left = new Node(3, { new Node(5, { }), new Node(6, { }) });
	Node *mid = new Node(2, { });
	Node *right = new Node(4, { });
	Node *root = new Node(1, { left, mid, right });
	cout << s.maxDepth(root) << endl;

	return 0;
}
