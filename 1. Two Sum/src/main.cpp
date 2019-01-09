#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> result;

		for (unsigned int i = 0; i < nums.size() - 1; i++)
		{
			for (unsigned int j = i + 1; j < nums.size(); j++)
			{
				if (nums[j] == target - nums[i])
				{
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		}
	}
};

class Solution2
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> returnVector;
		vector<int>::iterator vectorIterator1, vectorIterator2;
		int num1 = 0, num2 = 0;
		for (vectorIterator1 = nums.begin(); vectorIterator1 != nums.end(); ++vectorIterator1)
		{
			num1 = *vectorIterator1;
			for (vectorIterator2 = next(vectorIterator1); vectorIterator2 != nums.end(); ++vectorIterator2)
			{
				num2 = target - num1;
				if (*vectorIterator2 == num2)
				{
					returnVector.push_back(distance(nums.begin(), vectorIterator1));
					returnVector.push_back(distance(nums.begin(), vectorIterator2));
					return returnVector;
				}
			}
		}
	}
};

class Solution3
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> returnVector;
		map<int, int> IntMap;
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			int complement = target - nums[i];

			if (IntMap.find(complement) != IntMap.end())
			{
				returnVector.push_back(IntMap.find(complement)->second);
				returnVector.push_back(i);
				return returnVector;
			}
			IntMap[nums[i]] = i;
		}
	}
};

int main()
{
	Solution3 s;

	vector<int> nums { 3, 2, 4 };
	s.twoSum(nums, 6);
	return 0;
}
