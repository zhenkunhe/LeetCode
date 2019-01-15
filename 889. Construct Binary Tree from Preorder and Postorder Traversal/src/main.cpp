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
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post)
	{
		int size = pre.size();
		if ( size == 0 ) return nullptr;
		if ( size == 1 ) return new TreeNode(pre[0]);

		TreeNode *root = new TreeNode(pre[0]);
		int loc = distance(post.begin(), find(post.begin(), post.end(), pre[1])) + 1;

		vector<int> pre_vector_l(&pre[1], &pre[loc + 1]);
		vector<int> post_vector_l(&post[0], &post[loc]);
		vector<int> pre_vector_r(&pre[loc + 1], &pre[size]);
		vector<int> post_vector_r(&post[loc], &post[size - 1]);

		root->left = constructFromPrePost(pre_vector_l, post_vector_l);
		root->right = constructFromPrePost(pre_vector_r, post_vector_r);

		return root;
	}
};

class Solution2
{
public:
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post)
	{
		return constructFromPrePost(pre, post, 0, 0, pre.size());
	}

	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post, int i0, int i1, int size)
	{
		if ( size == 0 ) return nullptr;
		if ( size == 1 ) return new TreeNode(pre[i0]);

		TreeNode *root = new TreeNode(pre[i0]);
		int size_l = distance(post.begin(), find(post.begin(), post.end(), pre[i0 + 1])) + 1 - i1;

		root->left = constructFromPrePost(pre, post, i0 + 1, i1, size_l);
		root->right = constructFromPrePost(pre, post, i0 + 1 + size_l, i1 + size_l, size - size_l - 1);

		return root;
	}
};

int main()
{
	Solution s;
	vector<int> pre { 1, 2, 4, 5, 3, 6, 7 };
	vector<int> post { 4, 5, 2, 6, 7, 3, 1 };
	TreeNode* res = s.constructFromPrePost(pre, post);

	cout << res->val << endl;
	cout << res->left->val << endl;
	cout << res->right->val << endl;
	cout << res->left->left->val << endl;
	cout << res->left->right->val << endl;
	cout << res->right->left->val << endl;
	cout << res->right->right->val << endl;
	return 0;
}
