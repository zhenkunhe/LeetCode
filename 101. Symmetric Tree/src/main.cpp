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

// Top-down Solution
class Solution
{
public:
    bool isSymmetric(TreeNode* root)
	{
    	isSymmetric(root->left);
    	isSymmetric(root->right);
		return 1;
	}
};

int main()
{
	Solution s;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(3);

	cout << s.isSymmetric(root);
	return 0;
}
