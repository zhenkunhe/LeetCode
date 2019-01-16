#include <iostream>
#include <tree.hpp>

using namespace std;

// Top-down Solution
class Solution
{
public:
	int maxDepth(TreeNode* root)
	{
		return maxDepth(root, 1);
	}

	int maxDepth(TreeNode* root, int depth)
	{
		if ( !root ) return 0;
		if ( !root->left && !root->right ) return depth;
		return max(maxDepth(root->left, depth + 1), maxDepth(root->right, depth + 1));
	}
};

// Button-up Solution
class Solution2
{
public:
	int maxDepth(TreeNode* root)
	{
		if ( !root ) return 0;
		int left_ans = maxDepth(root->left);
		int right_ans = maxDepth(root->right);
		return max(left_ans, right_ans) + 1;
	}
};

int main()
{
	Solution2 s;
	TreeNode* root = stringToTreeNode("[3,9,20,null,null,15,7]");
	prettyPrintTree(root);
	cout << s.maxDepth(root);

	return 0;
}
