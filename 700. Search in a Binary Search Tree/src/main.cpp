#include <iostream>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	TreeNode* searchBST(TreeNode* root, int val)
	{
		if ( !root || val == root->val ) return root;
		if ( val > root->val ) return searchBST(root->right, val);
		return searchBST(root->left, val);
	}
};

class Solution2
{
public:
	TreeNode* searchBST(TreeNode* root, int val)
	{
		TreeNode *cur = root;
		while (cur && cur->val != val)
		{
			if ( val > cur->val ) cur = cur->right;
			else cur = cur->left;
		}
		return cur;
	}
};

int main()
{
	auto alex = []()
	{	std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

	Solution s;

	TreeNode *root = stringToTreeNode("[4,2,7,1,3]");
	prettyPrintTree(root);
	cout << endl << s.searchBST(root, 2)->val << endl;

	return 0;
}
