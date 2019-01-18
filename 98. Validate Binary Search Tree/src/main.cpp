#include <iostream>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	bool isValidBST(TreeNode* root)
	{
		if ( !root ) return true;
		bool isleft = true, isright = true;
		if ( root->left )
		{
			isleft = isValidBST(root->left) && root->left->val < root->val;
		}
		if ( root->right )
		{
			isright = isValidBST(root->right) && root->right->val > root->val;
		}
		return isright && isleft;
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
