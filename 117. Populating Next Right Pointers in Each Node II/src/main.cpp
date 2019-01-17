#include <iostream>
#include <queue>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	void connect(TreeLinkNode *root)
	{
		if ( !root ) return;

		if ( root->right )
		{
			for (TreeLinkNode *it = root->next; it && !root->right->next; it = it->next)
			{
				if ( it->left ) root->right->next = it->left;
				else if ( it->right ) root->right->next = it->right;
			}
			connect(root->right);
		};

		if ( root->left )
		{
			for (TreeLinkNode *it = root; it && !root->left->next; it = it->next)
			{
				if ( it->left && it->left != root->left ) root->left->next = it->left;
				else if ( it->right ) root->left->next = it->right;
			}
			connect(root->left);
		};
	}
};

class Solution2
{
public:
	void connect(TreeLinkNode *root)
	{
		if ( !root || (!root->left && !root->right) ) return;
		TreeLinkNode *tempRoot = root, *tempIter = new TreeLinkNode(-1);
		while( tempRoot && !tempIter->next )
		{
			if ( tempRoot->left ) tempIter = tempIter->next = tempRoot->left;
			if ( tempRoot->right ) tempIter = tempIter->next = tempRoot->right;
			tempRoot = tempRoot->next;
		}
		connect(root->left);
		connect(root->right);
	}
};

class Solution3
{
public:
	void connect(TreeLinkNode *root)
	{
		if ( !root ) return;
		queue<TreeLinkNode*> q;
		q.push(root);
		while( !q.empty() )
		{
			int size = q.size();
			for (int i = 1; i <= size; i++)
			{
				TreeLinkNode *front = q.front();
				q.pop();
				if ( front->left ) q.push(front->left);
				if ( front->right ) q.push(front->right);
				if ( i != size ) front->next = q.front();
			}
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
