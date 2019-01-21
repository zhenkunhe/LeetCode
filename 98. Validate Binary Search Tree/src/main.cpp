#include <iostream>
#include <limits.h>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	bool isValidBST(TreeNode* root)
	{
		return isValidBST(root, nullptr, nullptr);
	}
	bool isValidBST(TreeNode* root, int* low, int* high)
	{
		if ( !root ) return true;
		if ( (low && root->val <= *low) || (high && root->val >= *high) ) return false;
		return isValidBST(root->left, low, &root->val) && isValidBST(root->right, &root->val, high);
	}
};

int main()
{
	Solution s;
	TreeNode *root = stringToTreeNode("[5,1,4,null,null,3,6]");
	prettyPrintTree(root);
	cout << s.isValidBST(root) << endl;

	TreeNode *root2 = stringToTreeNode("[2,1,3]");
	prettyPrintTree(root2);
	cout << endl << s.isValidBST(root2) << endl;

	TreeNode *root3 = stringToTreeNode("[10,5,15,null,null,6,20]");
	prettyPrintTree(root3);
	cout << endl << s.isValidBST(root3) << endl;

	return 0;
}
