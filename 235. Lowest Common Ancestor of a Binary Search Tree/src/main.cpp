#include <iostream>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if ( !root || root == p || root == q ) return root;
		TreeNode *cur = root;
		while (true)
		{
			if ( cur == q || cur == p || cur->val < max(p->val, q->val) && cur->val > min(p->val, q->val) ) return cur;
			cur = (cur->val < p->val) && cur->val < q->val ? cur->right : cur->left;
		}
	}
};

class Solution2
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if ( !root || root == p || root == q ) return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if ( left && right ) return root;
		return left ? left : right;
	}
};

int main()
{
	Solution s;
	TreeNode *root = stringToTreeNode("[6,2,8,0,4,7,9,null,null,3,5]");
	prettyPrintTree(root);
	cout << s.lowestCommonAncestor(root, root->left, root->right)->val << endl;
	cout << s.lowestCommonAncestor(root, root->left, root->left->right->right)->val << endl;

	return 0;
}
