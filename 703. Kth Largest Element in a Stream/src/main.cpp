#include <iostream>
#include<queue>

struct Node
{
	Node* left;
	Node* right;
	int val;
	int cnt;
	Node(int v, int c) :
			left(NULL), right(NULL), val(v), cnt(c)
	{
	}
};

using namespace std;

class KthLargest
{
public:
	KthLargest(int k, vector<int> nums) :
			k_(k)
	{
		for (auto num : nums)
			add(num);
	}

	int add(int val)
	{
		if ( pq_.size() < k_ ) pq_.push(val);
		else if ( val > pq_.top() )
		{
			pq_.pop();
			pq_.push(val);
		}
		return pq_.top();
	}

private:
	//  min heap
	priority_queue<int, vector<int>, greater<int> > pq_;
	uint k_;
};

class KthLargest2
{
public:
	KthLargest2(int k, vector<int> nums) :
			root_(nullptr), k_(k)
	{
		for (auto num : nums)
			root_ = insertNode(root_, num);
	}

	int add(int val)
	{
		root_ = insertNode(root_, val);
		return searchKth(root_, k_);
	}

private:
	Node *insertNode(Node *root, int num)
	{
		Node **cur = &root;
		while (*cur)
		{
			(*cur)->cnt++;
			cur = (num > (*cur)->val) ? &(*cur)->right : &(*cur)->left;
		}
		*cur = new Node(num, 1);
		return root;
	}

	int searchKth(Node *root, int k)
	{
		Node *cur = root;
		int cnt = 0;
		while (true)
		{
			cnt = cur->right ? cur->right->cnt : 0;
			if ( k <= cnt ) cur = cur->right;		//cnt = cur->right->cnt
			else if ( k == cnt + 1 ) break;			//cnt = cur->right->cnt  or 0
			else
			{
				k = k - cnt - 1;
				cur = cur->left;
			}
		}
		return cur->val;
	}

	Node *root_;
	int k_;
};

int main()
{
	auto alex = []()
	{	std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

	int k = 3;
	vector<int> nums = { 4, 5, 8, 2 };
	KthLargest kthLargest(3, nums);
	cout << kthLargest.add(3) << endl;  // returns 4
	cout << kthLargest.add(5) << endl;   // returns 5
	cout << kthLargest.add(10) << endl;  // returns 5
	cout << kthLargest.add(9) << endl;   // returns 8
	cout << kthLargest.add(4) << endl;   // returns 8

	return 0;
}
