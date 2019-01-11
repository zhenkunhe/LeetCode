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
	bool hasPathSum(TreeNode* root, int sum)
	{
		if ( !root ) return false;

		int rest = sum - root->val;
		if ( !root->left && !root->right && rest == 0 ) return true;
		return hasPathSum(root->left, rest) || hasPathSum(root->right, rest);
	}
};

int main()
{
	Solution s;
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->right->right = new TreeNode(1);

	int sum = 22;

	cout << s.hasPathSum(root, sum);
	return 0;
}
