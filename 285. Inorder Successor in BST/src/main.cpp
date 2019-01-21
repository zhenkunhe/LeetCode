#include <iostream>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
	{
		if ( !root ) return nullptr;
		if ( p->val >= root->val ) return inorderSuccessor(root->right, p);
		TreeNode *left = inorderSuccessor(root->left, p);
		return left ? left : root;
	}
};

class Solution2
{
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
	{
		TreeNode* res = nullptr;

		while (root)
		{
			if ( p->val < root->val )
			{
				res = root;
				root = root->left;
			}
			else root = root->right;
		}
		return res;
	}
};

int main()
{
	Solution s;
	TreeNode *root = stringToTreeNode("[2,1,3]");
	prettyPrintTree(root);
	cout << s.inorderSuccessor(root, root->left)->val << endl;

	TreeNode *root2 = stringToTreeNode("[5,3,6,2,4,null,null,1]");
	prettyPrintTree(root2);
	cout << endl << s.inorderSuccessor(root2, root2->left)->val << endl;

	return 0;
}
