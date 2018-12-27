#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		int max = INT_MIN, sum = 0;

		for (auto i : nums)
		{
			sum = (sum > 0) ? sum + i : i;
			if (sum > max) max = sum;
		}
		return max;
	}
};

int main()
{
	Solution s;
	vector<int> nums { -1 };

	s.maxSubArray(nums);
	return 0;
}
