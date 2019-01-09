#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL)
	{
	}
};

class Solution
{
public:
	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> res, left, right;
		if (!root) return res;

		left = postorderTraversal(root->left);
		right = postorderTraversal(root->right);

		res.insert(res.end(), left.begin(), left.end());
		res.insert(res.end(), right.begin(), right.end());
		res.push_back(root->val);

		return res;
	}
};

class Solution2
{
public:
	vector<int> postorderTraversal(TreeNode* root)
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
				s.push(new TreeNode(top->val));
				if (top->right) s.push(top->right);
				if (top->left) s.push(top->left);
			}
		}

		return res;
	}
};

int main()
{
	Solution2 s;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(0);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(2);
	root->right->right = new TreeNode(4);

	vector<int> res = s.postorderTraversal(root);
	for (auto i : res)
	{
		cout << i << endl;
	}
	return 0;
}
