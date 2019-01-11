#include <iostream>

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
	int countUnivalSubtrees(TreeNode* root)
	{
		int ans = 0;
		isUnivalSubtrees(root, ans);
		return ans;
	}

	bool isUnivalSubtrees(TreeNode* root, int& ans)
	{
		if ( !root ) return true;
		bool equal_l = (root->left) ? isUnivalSubtrees(root->left, ans) && (root->val == root->left->val) : true;
		bool equal_r = (root->right) ? isUnivalSubtrees(root->right, ans) && (root->val == root->right->val) : true;
		if ( equal_l && equal_r )
		{
			ans++;
			return true;
		}
		return false;
	}
};

int main()
{
	Solution s;
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(1);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(5);
	root->right->right = new TreeNode(5);

	cout << s.countUnivalSubtrees(root);
	return 0;
}
