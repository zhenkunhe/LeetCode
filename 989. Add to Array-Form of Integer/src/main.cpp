#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
	vector<int> addToArrayForm(vector<int>& A, int K)
	{
		vector<int> result;
		if ( A.empty() ) return result;
		int sum = 0;
		bool carry = false;
		vector<int>::reverse_iterator it = A.rbegin();

		while (K != 0 || it != A.rend())
		{
			sum = K % 10 + carry;
			if ( it != A.rend() )
			{
				sum = sum + *it;
				it++;
			}
			carry = sum / 10;
			K = K / 10;
			result.insert(result.begin(), sum % 10);
		}
		if ( carry ) result.insert(result.begin(), 1);

		return result;
	}
};

int main()
{
	Solution s;

	vector<int> nums { 9 };
	vector<int> result = s.addToArrayForm(nums, 211);
	for (auto i : result)
	{
		cout << i << endl;
	}
	return 0;
}
