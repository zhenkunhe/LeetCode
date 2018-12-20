#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> result;
		if (nums.size() < 3) return result;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 2; i++)
		{
			int a = nums[i];
			if (a > 0) break;
			if (i && a == nums[i - 1]) continue;

			for  (int min = i + 1, max = nums.size() - 1;max > min;)
			{
				int value = a + nums[min] + nums[max];

				if (value > 0) --max;
				else if (value < 0) ++min;
				else
				{
					result.push_back(vector<int>{ a, nums[min], nums[max] });
					while (nums[max] == nums[--max]);
					while (nums[min] == nums[++min]);
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
	vector<int> nums;
	nums.push_back(-2);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);

	s.threeSum(nums);
	return 0;
}

