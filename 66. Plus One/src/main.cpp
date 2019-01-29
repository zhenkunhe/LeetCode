#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> plusOne(vector<int>& digits)
	{
		vector<int> res = digits;
		int carry = 1;
		for (vector<int>::reverse_iterator it = res.rbegin(); it != res.rend() && carry; it++)
			carry = (++*it %= 10) == 0;
		if ( carry ) res.insert(res.begin(), 1);

		return res;
	}
};

int main()
{
	Solution s;
	vector<int> digits { 9, 9, 9, 9 };
	vector<int> res = s.plusOne(digits);
	for (auto i : res)
	{
		cout << i << "\t";
	}
	cout << endl;

	return 0;
}
