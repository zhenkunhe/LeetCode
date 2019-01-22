#include <iostream>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	TreeNode *deleteNode(TreeNode *root, int key)
	{
		TreeNode **cur = &root;

		// Search target
		while (*cur && (*cur)->val != key)
			cur = (key > (*cur)->val) ? &(*cur)->right : &(*cur)->left;

		// if found
		if ( *cur )
		{
			if ( !(*cur)->right ) *cur = (*cur)->left;
			else
			{
				// 1.Search the successor
				TreeNode **successor = &(*cur)->right;
				while ((*successor)->left)	successor = &(*successor)->left;
				// 2.Swap the value
				swap((*cur)->val, (*successor)->val);
				// 3.Remove successor
				*successor = (*successor)->right ? (*successor)->right : nullptr;
			}
		}
		return root;
	}
};

int main()
{
	auto alex = []()
	{	std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

	Solution s;

	TreeNode *root = stringToTreeNode("[5,3,6,2,4,null,7]");
	prettyPrintTree(root);
	prettyPrintTree(s.deleteNode(root, 3));

	return 0;
}
