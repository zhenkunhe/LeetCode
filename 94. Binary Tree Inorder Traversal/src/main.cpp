#include <iostream>
#include <vector>
#include <stack>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		if (!root) return res;
		vector<int> res, left, right;

		left = inorderTraversal(root->left);
		right = inorderTraversal(root->right);

		res.insert(res.end(), left.begin(), left.end());
		res.push_back(root->val);
		res.insert(res.end(), right.begin(), right.end());

		return res;
	}
};

class Solution2
{
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> res;
		stack<TreeNode*> s;

		if (!root) return res;
		s.push(root);

		while (!s.empty())
		{
			TreeNode* top = s.top();
			s.pop();

			if (!top->right && !top->left) res.push_back(top->val);
			else
			{
				if (top->right) s.push(top->right);
				s.push(new TreeNode(top->val));
				if (top->left) s.push(top->left);
			}
		}

		return res;
	}
};

int main()
{
	Solution2 s;
	TreeNode* root = stringToTreeNode("[1,0,3,null,null,2,4]");
	prettyPrintTree(root);

	vector<int> res = s.inorderTraversal(root);
	for (auto i : res)
	{
		cout << i << "\t";
	}
	cout << endl;
	return 0;
}
