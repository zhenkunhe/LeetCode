#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

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

class Solution
{
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		if ( preorder.size() == 0 ) return nullptr;
		TreeNode *root = new TreeNode(preorder.front());

		int index = distance(inorder.begin(), find(inorder.begin(), inorder.end(), preorder.front()));

		vector<int>::iterator i = inorder.begin();
		vector<int>::iterator p = preorder.begin();

		vector<int> inorder_left(i, i + index);
		vector<int> inorder_right(i + index + 1, inorder.end());
		vector<int> preorder_left(p+1, p + 1+index);
		vector<int> preorder_right(p + 1 + index, preorder.end());

		root->left = buildTree(preorder_left, inorder_left);
		root->right = buildTree(preorder_right, inorder_right);
		return root;
	}
};

class Solution2
{
public:
	TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		int size = inorder.size() - 1;
		for (int i = 0; i <= size; ++i)
			index[inorder[i]] = i;
		cur = 0;
		return buildTree(preorder, inorder, 0, size);
	}

	TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder, int start, int end)
	{
		if ( end < start ) return nullptr;
		int val = preorder[cur++], loc = index[val]; // Move cur 1 higher (must be left of root, since preorder)
		TreeNode *head = new TreeNode(val);
		head->left = buildTree(preorder, inorder, start, loc - 1);
		head->right = buildTree(preorder, inorder, loc + 1, end);
		return head;
	}

private:
	int cur;
	unordered_map<int, int> index;
};

int main()
{
	Solution2 s;
	vector<int> preorder { 3, 9, 20, 15, 7 };
	vector<int> inorder { 9, 3, 15, 20, 7 };
	TreeNode* res = s.buildTree(preorder, inorder);

	cout << res->val << endl;
	cout << res->left->val << endl;
	cout << res->right->val << endl;
	cout << res->right->left->val << endl;
	cout << res->right->right->val << endl;

	return 0;
}
