#include <math.h>
#include <unistd.h>
#include <iostream>

using namespace std;

class Solution
{
	public:
		int numSquares( int n )
		{
			int resultArray[n + 1];
			if ( n == 0 ) return 0;
			if ( n == 1 ) return 1;
			if ( n == 2 ) return 2;
			resultArray[0] = 0;
			resultArray[1] = 1;
			resultArray[2] = 2;

			for (int i = 3; i <= n; i++)
			{
				bool first = true;
				for (int j = 1; j <= (int) sqrt( i ); j++)
				{
					int rest = i - j * j;

					if ( first )
					{
						first = false;
						resultArray[i] = 1 + resultArray[rest];
					}
					else
					{
						resultArray[i] = (1 + resultArray[rest] < resultArray[i]) ? 1 + resultArray[rest] : resultArray[i];
					}
				}
				cout << "number:" << i  << "\tresult:" << resultArray[i] << endl;
			}
			return resultArray[n];
		}
};

int main()
{
	Solution solution;
	cout << solution.numSquares( 600 ) << endl;
	return 0;
}
