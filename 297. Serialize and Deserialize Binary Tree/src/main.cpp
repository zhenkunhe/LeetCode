#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <tree.hpp>

using namespace std;

class Codec
{
public:
	string serialize(TreeNode* root)
	{
		if ( !root ) return "[]";

		string output = "";
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			TreeNode* node = q.front();
			q.pop();

			if ( node )
			{
				output += to_string(node->val) + ", ";
				q.push(node->left);
				q.push(node->right);
			}
			else output += "null, ";
		}

		return "[" + output.substr(0, output.length() - 2) + "]";
	}

	TreeNode* deserialize(string data)
	{
		TreeNode* root = nullptr;
		string item = "";
		queue<TreeNode**> q;
		istringstream ss(data.substr(1, data.length() - 2));
		q.push(&root);

		while (!q.empty() && getline(ss, item, ','))
		{
			TreeNode** node = q.front();
			q.pop();

			if ( item.find("null") == string::npos )
			{
				*node = new TreeNode(stoi(item));
				q.push(&(*node)->left);
				q.push(&(*node)->right);
			}
		}
		return root;
	}
};

int main()
{
	Codec c;
	TreeNode *root1 = stringToTreeNode("[1,2,3,null,null,4,5]");
	prettyPrintTree(root1);
	TreeNode *root2 = c.deserialize("[1,2,3,null,null,4,5]");
	prettyPrintTree(root2);

	string s1 = treeNodeToString(root1);
	cout << s1 << endl;
	string s2 = c.serialize(root2);
	cout << s2 << endl;

	return 0;
}
