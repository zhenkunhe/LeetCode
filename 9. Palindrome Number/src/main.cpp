#include <iostream>

using namespace std;

class Solution
{
public:
	bool isPalindrome(int x)
	{
		int result = 0, input = x;
		if ( x < 0 ) return false;
		for (; x != 0; x = x / 10)
			result = result * 10 + x % 10;
		return input == result;
	}
};

class Solution2
{
public:
	bool isPalindrome(int x)
	{
		int result = 0;
		if ( x < 0 || (x % 10 == 0 && x != 0) ) return false;
		for (; x > result; x = x / 10)
		{
			result = result * 10 + x % 10;
		}
		return (x == result) || (x == result / 10);
	}
};

int main()
{
	Solution2 s;
	cout << s.isPalindrome(121);

	return 0;
}
