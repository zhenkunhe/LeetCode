#include <iostream>
#include<limits.h>
using namespace std;

class Solution
{
public:
	int reverse(int x)
	{
		int result = 0;
		for (; x != 0; x = x / 10)
		{
			int before = result;
			result = result * 10 + (x % 10);
			if ( before != 0 && result / before < 10 ) return 0;
		}
		return result;
	}
};

class Solution2
{
public:
	int reverse(int x)
	{
		int result = 0;
		for (; x != 0; x = x / 10)
		{
			int pop = x % 10;
			if ( result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7) ) return 0;
			if ( result < INT_MIN / 10 || (result == INT_MIN / 10 && pop > 8) ) return 0;
			result = result * 10 + pop;
		}
		return result;
	}
};

int main()
{
	Solution s;
	cout << s.reverse(123) << endl;
	cout << s.reverse(-123) << endl;
	cout << s.reverse(120) << endl;
	cout << s.reverse(1534236469) << endl;
	cout << s.reverse(8192) << endl;

	return 0;
}
