#include <iostream>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	TreeNode* insertIntoBST(TreeNode* root, int val)
	{
		if ( !root ) return new TreeNode(val);
		if ( val > root->val ) root->right = insertIntoBST(root->right, val);
		else root->left = insertIntoBST(root->left, val);
		return root;
	}
};

class Solution2
{
public:
	TreeNode *insertIntoBST(TreeNode *root, int val)
	{
		TreeNode **cur = &root;
		while (*cur)
		{
			if ( val > (*cur)->val ) cur = &(*cur)->right;
			else cur = &(*cur)->left;
		}
		*cur = new TreeNode(val);
		return root;
	}
};

int main()
{
	auto alex = []()
	{	std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

	Solution s;

	TreeNode *root = stringToTreeNode("[4,2,7,1,3]");
	prettyPrintTree(root);
	prettyPrintTree(s.insertIntoBST(root, 5));

	return 0;
}
