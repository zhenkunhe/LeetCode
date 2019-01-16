#include <iostream>
#include <tree.hpp>

using namespace std;

/*	        1
	      2        3
	  4     5    #     6
	7#  ##   ##  8#*/

class Solution
{
public:
	void connect(TreeLinkNode *root)
	{
		if ( !root ) return;

		if ( root->right )
		{
			for(TreeLinkNode *next = root->next;next;next = next->next)
			{
				if ( next->left )
				{
					root->right->next = next->left;
					break;
				}
				else if ( next->right )
				{
					root->right->next = next->right;
					break;
				}
			}
			connect(root->right);
		}
		if ( root->left )
		{
			if ( root->right ) root->left->next = root->right;
			else
			{
				for(TreeLinkNode *next = root->next;next;next = next->next)
				{
					if ( next->left )
					{
						root->left->next = next->left;
						break;
					}
					else if ( next->right )
					{
						root->left->next = next->right;
						break;
					}
				}
			}
			connect(root->left);
		}
	}
};

int main()
{
	Solution s;
	TreeLinkNode *root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	root->left->left = new TreeLinkNode(4);
	root->left->right = new TreeLinkNode(5);
	root->right->right = new TreeLinkNode(6);
	root->left->left->left = new TreeLinkNode(7);
	root->right->right->left = new TreeLinkNode(8);
	s.connect(root);

	cout << root->val << endl;
	cout << root->left->val << "\t";
	cout << root->left->next->val << endl;
	cout << root->left->left->val << "\t";
	cout << root->left->left->next->val << "\t";
	cout << root->left->left->next->next->val << endl;
	cout << root->left->left->left->val << "\t";
	cout << root->left->left->left->next->val << endl;

	return 0;
}
