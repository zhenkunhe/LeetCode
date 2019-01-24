#include <iostream>
#include <tree.hpp>

using namespace std;

class Codec
{
public:
	// Encodes an n-ary tree to a binary tree.
	TreeNode* encode(Node* root)
	{
		TreeNode *res = nullptr;
		return res;
	}

	// Decodes your binary tree to an n-ary tree.
	Node* decode(TreeNode* root)
	{
		Node *res = nullptr;
		return res;
	}
};

int main()
{
	TreeNode *root = stringToTreeNode("[1,3,2,5,null,null,4,null,6]");
	prettyPrintTree(root);

	Node *left = new Node(3, { new Node(5, { }), new Node(6, { }) });
	Node *mid = new Node(2, { });
	Node *right = new Node(4, { });
	Node *root2 = new Node(1, { left, mid, right });

	Codec codec;
	codec.decode(root);
	codec.encode(root2);

	return 0;
}
