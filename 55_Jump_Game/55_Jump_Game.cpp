#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool canJump(vector<int>& nums)
	{
		int checkedPos = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (checkedPos < i)	break;
			else if (checkedPos < i + nums[i]) checkedPos = i + nums[i];
		}
		return (checkedPos >= nums.size() - 1);
	}
};

int main()
{
	Solution s;

	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);

	cout << s.canJump(nums);

	return 0;
}
