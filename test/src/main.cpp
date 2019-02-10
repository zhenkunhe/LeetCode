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
		int c = 0, rest = 0;
		for (vector<int>::reverse_iterator it = A.rbegin(); it != A.rend(); it++)
		{
			rest = K % 10;
			K = K / 10;
			//cout << rest << endl;
			//cout << K << endl;
			//cout << *it << endl;
			if ( *it + rest + c >= 10 )
			{
				*it = (*it + rest + c) % 10;
				c = 1;
			}
			else
			{
				*it = (*it + rest + c) % 10;
				c = 0;
			}

			//cout << *it << endl;
			result.insert(result.begin(), *it);
		}
		while ( K + c != 0 )
		{
			rest = K % 10;
			K = K / 10;
			int res;
			if ( rest + c >= 10 )
			{
				res = (rest + c) % 10;
				c = 1;
			}
			else
			{
				res = (rest + c) % 10;
				c = 0;
			}
			result.insert(result.begin(), res);
		}
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
