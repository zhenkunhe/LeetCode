#include <iostream>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	TreeNode* deleteNode(TreeNode* root, int key)
	{
		return nullptr;
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
