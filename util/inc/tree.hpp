#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

class Node
{
public:
	int val;
	vector<Node*> children;

	Node()
	{
	}

	Node(int _val, vector<Node*> _children)
	{
		val = _val;
		children = _children;
	}
};

struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) :
			val(x), left(NULL), right(NULL), next(NULL)
	{
	}
};

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

string treeNodeToString(TreeNode* root);

void trimLeftTrailingSpaces(string &input);

void trimRightTrailingSpaces(string &input);

TreeNode* stringToTreeNode(string input);

void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true);
