#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int dominantIndex(vector<int>& nums)
	{
		if ( nums.size() == 0 ) return -1;
		int max = 0, sec = 0, size = nums.size();
		for (int i = 1; i < size; i++)
		{
			if ( nums[i] > nums[max] )
			{
				sec = max;
				max = i;
			}
			else if ( nums[i] > nums[sec] || max == sec ) sec = i;
		}

		return (nums[max] >= nums[sec] * 2 || max == sec) ? max : -1;
	}
};

int main()
{
	Solution s;
	vector<int> nums { 3, 6, 1, 0 };
	cout << s.dominantIndex(nums) << endl;

	return 0;
}
