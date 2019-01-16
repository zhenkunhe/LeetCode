#include <iostream>
#include <deque>
#include <queue>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	bool isSymmetric(TreeNode* root)
	{
		deque<TreeNode*> q;
		TreeNode* cur;
		q.push_back(root);

		while (!q.empty())
		{
			int size = q.size();

			for (int left = 0, right = size - 1; left < right; left++, right--)
			{
				if ( q[left] && q[right] && q[left]->val != q[right]->val ) return false;
				if ( (!q[left] && q[right]) || (q[left] && !q[right]) ) return false;
			}

			for (int i = 0; i < size; i++)
			{
				cur = q.front();
				q.pop_front();
				if ( !cur ) continue;
				q.push_back(cur->left);
				q.push_back(cur->right);
			}
		}
		return true;
	}
};

class Solution2
{
public:
	bool isSymmetric(TreeNode *root)
	{
		if ( !root ) return true;
		return isSymmetric(root->left, root->right);
	}
	bool isSymmetric(TreeNode *left, TreeNode *right)
	{
		if ( !left && !right ) return true;
		if ( left && !right || !left && right || left->val != right->val ) return false;
		return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
	}
};

class Solution3
{
public:
	bool isSymmetric(TreeNode* root)
	{
		if ( !root ) return true;
		queue<TreeNode*> q1, q2;
		q1.push(root->left);
		q2.push(root->right);

		while (!q1.empty() && !q2.empty())
		{
			TreeNode *node1 = q1.front();
			q1.pop();
			TreeNode *node2 = q2.front();
			q2.pop();
			if ( !node1 && !node2 ) continue;
			if ( (node1 && !node2) || (!node1 && node2) ) return false;
			if ( node1->val != node2->val ) return false;
			q1.push(node1->left);
			q1.push(node1->right);
			q2.push(node2->right);
			q2.push(node2->left);
		}
		return true;
	}
};

int main()
{
	Solution s;
	TreeNode* root = stringToTreeNode("[1,2,2,3,4,4,3]");
	prettyPrintTree(root);
	cout << s.isSymmetric(root)<<endl;

	TreeNode* root2 = stringToTreeNode("[1,2,2,null,3,null,3]");
	prettyPrintTree(root2);
	cout << s.isSymmetric(root2)<<endl;
	return 0;
}
