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
		if (nums.size() < 3)
			return result;

		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++)
		{
			if (nums[i] > 0)
				break;
			if (i != 0 && nums[i] == nums[i - 1])
				continue;
			int min = i + 1;
			int max = nums.size() - 1;
			while (max > min)
			{
				if (nums[i] + nums[min] + nums[max] > 0)
				{
					do
					{
						max--;
					} while (nums[max] == nums[max + 1]);
				}
				else if (nums[i] + nums[min] + nums[max] < 0)
				{
					do
					{
						min++;
					} while (nums[min] == nums[min - 1]);
				}
				else if (nums[i] + nums[min] + nums[max] == 0)
				{
					result.push_back(vector<int>
					{ nums[i], nums[min], nums[max] });
					do
					{
						max--;
					} while (nums[max] == nums[max + 1]);
					do
					{
						min++;
					} while (nums[min] == nums[min - 1]);
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
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);

	s.threeSum(nums);
	return 0;
}

