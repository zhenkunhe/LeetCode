#include <iostream>
#include <stack>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	vector<int> postorder(Node* root)
	{
		vector<int> res;
		if ( root )
		{
			vector<int> child_res;
			for (auto child : root->children)
			{
				child_res = postorder(child);
				res.insert(res.end(), child_res.begin(), child_res.end());
			}
			res.push_back(root->val);
		}
		return res;
	}
};

class Solution2
{
public:
	vector<int> postorder(Node* root)
	{
		vector<int> res;
		stack<Node*> s;
		if ( root )
		{
			s.push(root);
			while (!s.empty())
			{
				Node *top = s.top();
				s.pop();

				if ( top->children.size() == 0 ) res.push_back(top->val);
				else s.push(new Node(top->val, { }));
				for (vector<Node*>::reverse_iterator it = top->children.rbegin(); it != top->children.rend(); it++)
					s.push(*it);
			}
		}
		return res;
	}
};

int main()
{
	Solution2 s;
	Node *left = new Node(3, { new Node(5, { }), new Node(6, { }) });
	Node *mid = new Node(2, { });
	Node *right = new Node(4, { });
	Node *root = new Node(1, { left, mid, right });
	vector<int> res = s.postorder(root);
	for (auto i : res)
	{
		cout << i << "\t";
	}
	cout << endl;

	return 0;
}
