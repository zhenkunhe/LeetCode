#include <iostream>
#include <vector>
#include <set>
#include <tree.hpp>

using namespace std;

class BST
{
public:
	BST() :
			root_(nullptr)
	{
	}
	TreeNode *insert(int val)
	{
		root_ = insert(root_, val);
		return root_;
	}

	TreeNode *insert(TreeNode *root, int val)
	{
		TreeNode **cur = &root;
		while( *cur )
			cur = (val > (*cur)->val) ? &(*cur)->right : &(*cur)->left;
		*cur = new TreeNode(val);
		return root;
	}

	TreeNode *remove(int val)
	{
		root_ = remove(root_, val);
		return root_;
	}

	TreeNode *remove(TreeNode *root, int val)
	{
		TreeNode **cur = &root;

		while( *cur && (*cur)->val != val )
			cur = (val > (*cur)->val) ? &(*cur)->right : &(*cur)->left;

		if ( *cur )
		{
			if ( !(*cur)->right ) *cur = (*cur)->left;
			else
			{
				TreeNode **successor = &(*cur)->right;
				while( (*successor)->left )
					successor = &(*successor)->left;
				swap((*cur)->val, (*successor)->val);
				*successor = (*successor)->right ? (*successor)->right : nullptr;
			}
		}
		return root;
	}

	bool search(int val, int t)
	{
		return search(root_, val, t);
	}

	bool search(TreeNode *root, long val, int t)
	{
		while( root )
		{
			if ( abs(val - root->val) <= t ) return true;
			root = (val > root->val) ? root->right : root->left;
		}
		return false;
	}

private:
	TreeNode *root_;
};

class Solution
{
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
	{
		if ( nums.empty() || k == 0 ) return false;
		BST bst;
		for (int i = 1; i < nums.size(); i++)
		{
			if ( i > k ) bst.remove(nums[i - k - 1]);
			bst.insert(nums[i - 1]);
			if ( bst.search(nums[i], t) ) return true;
		}
		return false;
	}
};

class Solution2
{
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
	{
		multiset<long> s;
		if ( nums.empty() || k == 0 ) return false;

		for (int i = 0; i < nums.size(); i++)
		{
			if ( i > k ) s.erase(nums[i - k - 1]);
			s.emplace(nums[i]);
			auto it = s.find(nums[i]);
			if ( it != s.begin() && abs(*prev(it) - *it) <= t ) return true;
			if ( next(it) != s.end() && abs(*it - *next(it)) <= t ) return true;
		}
		return false;
	}
};

class Solution3
{
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
	{
		set<long> s;
		if ( nums.empty() || k == 0 ) return false;

		for (int i = 0; i < nums.size(); i++)
		{
			if ( i > k ) s.erase(nums[i - k - 1]);
			auto pos = s.lower_bound((long) nums[i] - t);
			if ( pos != s.end() && *pos - nums[i] <= t ) return true;
			s.emplace(nums[i]);
		}
		return false;
	}
};

class Solution4
{
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
	{
		vector<pair<int64_t, int>> tmp;
		int64_t dat1;
		int dat2;
		for (uint i = 0; i < nums.size(); i++)
			tmp.push_back(make_pair(nums[i], i));

		sort(tmp.begin(), tmp.end(), [](const pair<int64_t, int>& left,const pair<int64_t, int>& right)
		{	return left.first < right.first;});

		int size = tmp.size(), i = 0, j = 1;

		while( j < size )
		{
			dat1 = tmp[j].first - tmp[i].first;
			dat2 = abs(tmp[j].second - tmp[i].second);
			if ( dat1 <= t && dat2 <= k ) return true;
			else if ( dat1 <= t || j == ++i ) j++;
		}

		return false;
	}
};

int main()
{
	Solution4 s;
	vector<int> nums = { 1, 2, 3, 1 };
	vector<int> nums2 = { 1, 0, 1, 1 };
	vector<int> nums3 = { 1, 5, 9, 1, 5, 9 };
	cout << s.containsNearbyAlmostDuplicate(nums, 3, 0) << endl;
	cout << s.containsNearbyAlmostDuplicate(nums2, 1, 2) << endl;
	cout << s.containsNearbyAlmostDuplicate(nums3, 2, 3) << endl;

	return 0;
}
