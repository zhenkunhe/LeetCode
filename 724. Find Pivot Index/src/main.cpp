#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int pivotIndex(vector<int>& nums)
	{
		if ( nums.size() == 0 ) return -1;
		int left = -1, right = nums.size(), sum_l = 0, sum_r = 0;
		while (left < right)
		{
			if ( sum_l < sum_r ) sum_l += nums[++left];
			else if ( sum_l > sum_r ) sum_r += nums[--right];
			else if ( sum_l == sum_r )
			{
				sum_l += nums[++left];
				sum_r += nums[--right];
			}
		}
		return left == right ? left : -1;
	}
};

int main()
{
	Solution s;
	vector<int> nums { 1, 7, 3, 6, 5, 6 };
	cout << s.pivotIndex(nums) << endl;

	return 0;
}
