#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
	int brokenCalc(int X, int Y)
	{
		int res = 0;
		if ( X > Y ) return X - Y;
		if ( X == Y ) return 0;
		if ( Y % 2 == 0 ) return brokenCalc(X, Y / 2) + 1;
		else return brokenCalc(X, (Y + 1) / 2) + 2;
	}
};

int main()
{
	Solution s;

	cout << s.brokenCalc(1, 10) << endl;

	return 0;
}
