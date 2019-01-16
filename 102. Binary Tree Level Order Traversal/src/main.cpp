#include <iostream>
#include <vector>
#include <queue>
#include <tree.hpp>

using namespace std;

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
	TreeNode* root = stringToTreeNode("[3,9,20,null,null,15,7]");
	prettyPrintTree(root);

	vector<vector<int>> res = s.levelOrder(root);
	for (auto l : res)
	{
		for (auto i : l)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}
