#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL)
	{
	}
};

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
		if (!root) return 0;
		if (!root->left && !root->right) return depth;
		return max(maxDepth(root->left, depth + 1), maxDepth(root->right, depth + 1));
	}
};

// Button-up Solution
class Solution2
{
public:
	int maxDepth(TreeNode* root)
	{
		if (!root) return 0;
		int left_ans = maxDepth(root->left);
		int right_ans = maxDepth(root->right);
		return max(left_ans, right_ans) + 1;
	}
};

int main()
{
	Solution2 s;
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	cout << s.maxDepth(root);
	return 0;
}
