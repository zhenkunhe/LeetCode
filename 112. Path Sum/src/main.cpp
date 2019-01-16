#include <iostream>
#include <tree.hpp>

using namespace std;

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
	TreeNode* root = stringToTreeNode("[5,4,8,11,null,13,4,7,2,null,null,null,1]");
	prettyPrintTree(root);

	int sum = 22;
	cout << s.hasPathSum(root, sum);
	return 0;
}
