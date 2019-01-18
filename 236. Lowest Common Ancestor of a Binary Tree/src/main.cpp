#include <iostream>
#include <vector>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if ( !root ||root == p || root == q ) return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if ( left && right ) return root;
		return left ? left : right;
	}
};

int main()
{
	Solution s;
	TreeNode *root = stringToTreeNode("[3,5,1,6,2,0,8,null,null,7,4]");
	prettyPrintTree(root);
	cout << s.lowestCommonAncestor(root, root->left, root->right)->val << endl;
	cout << s.lowestCommonAncestor(root, root->left, root->left->right->right)->val << endl;

	return 0;
}
