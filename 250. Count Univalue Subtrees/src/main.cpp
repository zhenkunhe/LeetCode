#include <iostream>
#include <tree.hpp>

using namespace std;

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
	TreeNode* root = stringToTreeNode("[5,1,5,5,5,null,5]");
	prettyPrintTree(root);

	cout << s.countUnivalSubtrees(root);
	return 0;
}
