#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		vector<int> add;
		int sum=0;
		int min=nums[0],max=nums[0];
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i]<<"\t";
		}
		cout << endl;

		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			add.push_back(sum);
			if (add[i]<=min)
			{
				min=add[i];
			}
			if (add[i]>max)
			{
				max=add[i];
			}
			cout << add[i]<<"\t";
		}

		cout << endl;
		cout << "min:"<<min<<endl;
		cout << "max:"<<max<<endl;
		return 0;
	}
};

int main()
{
	Solution s;
	vector<int> nums {-3,-2,-1 };

	s.maxSubArray(nums);
	return 0;
}
