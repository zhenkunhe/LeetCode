#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int pivotIndex(vector<int>& nums)
	{
		int size = nums.size();
		if ( size == 0 ) return -1;
		vector<int> sums = { 0 };

		for (int i = 0; i < size; i++)
			sums.push_back(sums.back() + nums[i]);

		for (int i = 1; i <= size ; i++)
			if ( sums[size] == sums[i - 1] + sums[i] ) return i - 1;

		return -1;
	}
};

int main()
{
	Solution s;
	vector<int> nums { -1, -1, -1, -1, -1, -1 };
	cout << s.pivotIndex(nums) << endl;

	return 0;
}
