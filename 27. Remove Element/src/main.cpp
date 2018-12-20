#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		while (find(nums.begin(), nums.end(), val) != nums.end())
		{
			nums.erase(find(nums.begin(), nums.end(), val));
		}
		return nums.size();
	}
};

int main()
{
	Solution s;
	vector<int> nums { 0, 1, 2, 2, 3, 0, 4, 2 };
	int val = 2;
	s.removeElement(nums, val);
	return 0;
}

