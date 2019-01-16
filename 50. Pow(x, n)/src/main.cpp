#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
	double myPow(double x, int n)
	{
		if ( x == 0 ) return 0;
		if ( x == 1 ) return 1;
		if ( x == -1 ) return n % 2 ? -1 : 1;

		map<long, double> history;
		double result = 1, dN = n;

		if ( n < 0 )
		{
			dN = -dN;
			x = 1 / x;
		}
		int p = 1;
		history[0] = 1;
		history[1] = x;
		while (p * 2 < dN)
		{
			x *= x;
			p <<= 1;
			if ( x == 0 ) return 0;
			history[p] = x;
		}
		long remain = dN;
		while (remain)
		{
			for (map<long, double>::reverse_iterator i = history.rbegin(); i != history.rend(); i++)
			{
				if ( remain >= i->first )
				{
					result *= i->second;
					remain -= i->first;
					break;
				}
			}
		}
		return result;
	}
};

class Solution2
{
public:
	double myPow(double x, int n)
	{
		if ( x == 0 ) return 0;
		if ( x == 1 ) return 1;
		if ( x == -1 ) return n % 2 ? -1 : 1;

		double result = 1.0;
		long p = n;
		if ( n < 0 )
		{
			p = -p;
			x = 1 / x;
		}
		for (; p; x *= x, p >>= 1)
		{
			if ( p & 1 ) result = result * x;
		}
		return result;
	}
};

int main()
{
	Solution2 s;
	double x = 2.1;
	int n = 3;
	cout << s.myPow(x, n);

	return 0;
}

