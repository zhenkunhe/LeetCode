#include <iostream>
#include <vector>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		bool is_p = false, is_q = false;
		return lowestCommonAncestor(root, p, q, is_p, is_q);
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, bool& is_p, bool& is_q)
	{
		if ( !root ) return nullptr;

		bool is_pl = false, is_ql = false;
		bool is_pr = false, is_qr = false;
		TreeNode* res_l = lowestCommonAncestor(root->left, p, q, is_pl, is_ql);
		TreeNode* res_r = lowestCommonAncestor(root->right, p, q, is_pr, is_qr);

		if ( res_l ) return res_l;
		if ( res_r ) return res_r;
		if ( root == p || is_pl || is_pr) is_p = true;
		if ( root == q || is_ql || is_qr) is_q = true;
		cout << root->val << "\t";
		cout << is_p << "\t";
		cout << is_q << "\t";

		cout << is_pl << "\t";
		cout << is_ql << "\t";

		cout << is_pr << "\t";
		cout << is_qr << endl;

		if ( is_q && is_p ) return root;


		return nullptr;
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
