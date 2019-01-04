#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxArea(vector<int>& height)
	{
		int max = 0;
		for (unsigned int i = 0; i < height.size() - 1; i++)
		{
			for (unsigned int j = i + 1; j < height.size(); j++)
			{
				int area = min(height[j], height[i]) * (j - i);
				if (area > max) max = area;
			}
		}
		return max;
	}
};

class Solution2
{
public:
	int maxArea(vector<int>& height)
	{
		int left = 0, right = height.size() - 1;
		int maxarea = 0;

		while (left < right)
		{
			maxarea = max(maxarea, min(height[left], height[right]) * (right - left));
			if (height[left] < height[right]) left++;
			else right--;
		}
		return maxarea;
	}
};

int main()
{
	Solution3 s;
	vector<int> height { 2, 3, 4, 5, 18, 17, 6 };
	cout << s.maxArea(height);
	return 0;
}
