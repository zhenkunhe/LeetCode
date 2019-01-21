#include <iostream>
#include <stack>
#include <tree.hpp>

using namespace std;

class BSTIterator
{
public:
	BSTIterator(TreeNode* root)
	{
		if ( root ) nodes_.emplace(root);
	}

	/** @return the next smallest number */
	int next()
	{
		TreeNode* top = nullptr;
		while (true)
		{
			top = nodes_.top();
			nodes_.pop();
			if ( !top->right && !top->left ) break;

			if ( top->right ) nodes_.emplace(top->right);
			nodes_.push(new TreeNode(top->val));
			if ( top->left ) nodes_.emplace(top->left);
		}
		return top->val;
	}

	/** @return whether we have a next smallest number */
	bool hasNext()
	{
		return !nodes_.empty();
	}
private:
	stack<TreeNode*> nodes_;
};

class BSTIterator2
{
public:
	stack<TreeNode*> nodes;
	BSTIterator2(TreeNode* root)
	{
		helper(root);
	}

	inline void helper(TreeNode *root)
	{
		while (root)
		{
			nodes.emplace(root);
			root = root->left;
		}
	}

	int next()
	{
		auto tmp = nodes.top();
		nodes.pop();
		helper(tmp->right);
		return tmp->val;
	}

	bool hasNext()
	{
		return !nodes.empty();
	}
};

int main()
{
	auto alex = []()
	{	std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

	TreeNode *root = stringToTreeNode("[7,3,15,null,null,9,20]");
	prettyPrintTree(root);

	BSTIterator iterator(root);
	cout << iterator.next() << endl;    // return 3
	cout << iterator.next() << endl;    // return 7
	cout << iterator.hasNext() << endl; // return true
	cout << iterator.next() << endl;    // return 9
	cout << iterator.hasNext() << endl; // return true
	cout << iterator.next() << endl;    // return 15
	cout << iterator.hasNext() << endl; // return true
	cout << iterator.next() << endl;    // return 20
	cout << iterator.hasNext() << endl; // return false

	return 0;
}
