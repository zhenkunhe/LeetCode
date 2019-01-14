#include <iostream>
#include <vector>

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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		return NULL;
	}
};

int main()
{
	Solution s;
	vector<int> inorder{9,3,15,20,7};
	vector<int> postorder{9,15,7,20,3};
	TreeNode* res = s.buildTree(inorder, postorder);

	return 0;
}
