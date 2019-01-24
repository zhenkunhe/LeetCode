#include <iostream>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	bool isBalanced(TreeNode* root)
	{
		if ( !root ) return true;
		return maxDepth(root) == -1 ? false : true;
	}
	int maxDepth(TreeNode* root)
	{
		if ( !root ) return 0;
		int left_depth = maxDepth(root->left);
		int right_depth = maxDepth(root->right);
		if ( left_depth == -1 || right_depth == -1 || abs(right_depth - left_depth) > 1 ) return -1;
		return max(left_depth, right_depth) + 1;
	}
};

int main()
{
	auto alex = []()
	{	std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

	Solution s;

	TreeNode *root = stringToTreeNode("[1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5]");
	prettyPrintTree(root);
	cout << s.isBalanced(root) << endl;

	TreeNode *root2 = stringToTreeNode("[1,2,2,3,3,null,null,4,4]");
	prettyPrintTree(root2);
	cout << s.isBalanced(root2) << endl;

	return 0;
}
