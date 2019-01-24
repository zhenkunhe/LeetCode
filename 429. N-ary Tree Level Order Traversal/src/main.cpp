#include <iostream>
#include <queue>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	vector<vector<int>> levelOrder(Node* root)
	{
		vector<vector<int>> res;
		queue<Node*> q;
		Node *front = nullptr;
		int size;

		if ( root )
		{
			q.push(root);
			while (!q.empty())
			{
				size = q.size();
				res.push_back( { });
				for (int i = 0; i < size; i++)
				{
					front = q.front();
					q.pop();
					for (auto child : front->children)
						q.push(child);

					res.back().push_back(front->val);
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	Node *left = new Node(3, { new Node(5, { }), new Node(6, { }) });
	Node *mid = new Node(2, { });
	Node *right = new Node(4, { });
	Node *root = new Node(1, { left, mid, right });
	vector<vector<int>> res = s.levelOrder(root);
	for (auto i : res)
	{
		for (auto j : i)
		{
			cout << j << "\t";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
