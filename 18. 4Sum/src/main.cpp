#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		vector<vector<int>> result;
		if ( nums.size() < 4 ) return result;
		sort(nums.begin(), nums.end());

		for (unsigned int i = 0; i < nums.size() - 3; i++)
		{
			int a = nums[i];
			if ( i && a == nums[i - 1] ) continue;

			for (unsigned int j = i + 1; j < nums.size() - 2; j++)
			{
				int b = nums[j];
				if ( j != i + 1 && b == nums[j - 1] ) continue;

				for (int min = j + 1, max = nums.size() - 1; max > min;)
				{
					int c = nums[min], d = nums[max];
					int value = a + b + c + d;

					if ( value > target ) --max;
					else if ( value < target ) ++min;
					else
					{
						result.push_back(vector<int> { a, b, c, d });
						while (nums[max] == nums[--max]);
						while (nums[min] == nums[++min]);
					}
				}
			}
		}
		return result;
	}
}
;
int main()
{
	Solution s;
	vector<int> nums = { 5, 5, 3, 5, 1, -5, 1, -2 };
	s.fourSum(nums, 4);
	return 0;
}

