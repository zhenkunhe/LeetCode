#include <iostream>
#include <vector>
#include <queue>

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
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> res;
		queue<pair<int, TreeNode*>> q;
		TreeNode* item = root;
		int level = 0;

		if (!root) return res;
		q.push(pair<int, TreeNode*>(level, item));

		while (!q.empty())
		{
			level = q.front().first;
			item = q.front().second;
			q.pop();

			if (item->left) q.push(pair<int, TreeNode*>(level + 1, item->left));
			if (item->right) q.push(pair<int, TreeNode*>(level + 1, item->right));
			if (res.size() != level + 1) res.resize(level + 1);
			res[level].push_back(item->val);
		}
		return res;
	}
};

class Solution2
{
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> res;
		queue<TreeNode*> q;
		TreeNode* cur ;

		if (!root) return res;
		q.push(root);

		while (!q.empty())
		{
			int size = q.size();
			res.push_back(vector<int>());

			for (int i = 0; i < size; i++)
			{
				cur = q.front();
				q.pop();

				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
				res.back().push_back((cur->val));
			}
		}
		return res;
	}
};

int main()
{
	Solution2 s;
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	vector<vector<int>> res = s.levelOrder(root);
	for (auto l : res)
	{
		for (auto i : l)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}
