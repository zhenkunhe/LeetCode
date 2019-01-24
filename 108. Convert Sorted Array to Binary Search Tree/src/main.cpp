#include <iostream>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		if ( nums.empty() ) return nullptr;
		int size = nums.size(), mid = floor(size / 2);
		TreeNode *res = new TreeNode(nums[mid]);

		if ( mid != 0 )
		{
			vector<int> vl(&nums[0], &nums[mid]);
			res->left = sortedArrayToBST(vl);
		}
		if ( mid != size - 1 )
		{
			vector<int> vr(&nums[mid + 1], &nums[size]);
			res->right = sortedArrayToBST(vr);
		}

		return res;
	}
};

int main()
{
	auto alex = []()
	{	std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

	Solution s;
	vector<int> nums = { -10, -3, 0, 5, 9 };
	prettyPrintTree(s.sortedArrayToBST(nums));

	return 0;
}
