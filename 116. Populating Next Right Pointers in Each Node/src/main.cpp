#include <iostream>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	void connect(TreeLinkNode *root)
	{
		if ( !root ) return;
		connect(root->left, root->right);
	}
	void connect(TreeLinkNode *left, TreeLinkNode *right)
	{
		if ( !left || !right ) return;
		left->next = right;
		connect(left->left, left->right);
		connect(left->right, right->left);
		connect(right->left, right->right);
	}
};

class Solution2
{
public:
	void connect(TreeLinkNode *root)
	{
		if ( !root ) return;
		if ( root->left )
		{
			root->left->next = root->right;
			if ( root->next ) root->right->next = root->next->left;
		}
		connect(root->left);
		connect(root->right);
	}
};

int main()
{
	Solution2 s;
	TreeLinkNode *root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	root->left->left = new TreeLinkNode(4);
	root->left->right = new TreeLinkNode(5);
	root->right->left = new TreeLinkNode(6);
	root->right->right = new TreeLinkNode(7);
	s.connect(root);

	cout << root->val << endl;
	cout << root->left->val << "\t";
	cout << root->left->next->val << endl;
	cout << root->left->left->val << "\t";
	cout << root->left->left->next->val << "\t";
	cout << root->left->left->next->next->val << "\t";
	cout << root->left->left->next->next->next->val << endl;

	return 0;
}
