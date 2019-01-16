#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		if ( postorder.size() == 0 ) return nullptr;
		TreeNode *root = new TreeNode(postorder.back());

		int index = distance(inorder.begin(), find(inorder.begin(), inorder.end(), postorder.back()));

		vector<int>::iterator i = inorder.begin();
		vector<int>::iterator p = postorder.begin();

		vector<int> inorder_left(i, i + index);
		vector<int> inorder_right(i + index + 1, inorder.end());
		vector<int> postorder_left(p, p + index);
		vector<int> postorder_right(p + index, postorder.end() - 1);

		root->left = buildTree(inorder_left, postorder_left);
		root->right = buildTree(inorder_right, postorder_right);
		return root;
	}
};

class Solution2
{
public:
	TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		int size = inorder.size() - 1;
		for (int i = 0; i <= size; ++i)
			index[inorder[i]] = i;
		cur = size;
		return buildTree(inorder, postorder, 0, size);
	}

	TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder, int start, int end)
	{
		if ( end < start ) return nullptr;
		int val = postorder[cur--], loc = index[val]; // Move cur 1 lower (must be right of root, since postorder)
		TreeNode *head = new TreeNode(val);
		head->right = buildTree(inorder, postorder, loc + 1, end);
		head->left = buildTree(inorder, postorder, start, loc - 1);
		return head;
	}

private:
	int cur;
	unordered_map<int, int> index;
};

int main()
{
	Solution s;
	vector<int> inorder { 9, 3, 15, 20, 7 };
	vector<int> postorder { 9, 15, 7, 20, 3 };
	prettyPrintTree(s.buildTree(inorder, postorder));

	return 0;
}
