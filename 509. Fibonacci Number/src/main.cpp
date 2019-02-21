#include <iostream>
#include <queue>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	int fib(int N)
	{
		if ( N == 0 ) return 0;
		if ( N == 1 ) return 1;
		vector<int> fibs(N + 1, 0);

		fibs[1] = 1;
		for (int i = 2; i <= N; i++)
		{
			fibs[i] = fibs[i - 1] + fibs[i - 2];
		}
		return fibs[N];
	}
};

int main()
{
	Solution s;
	cout << s.fib(30) << endl;

	return 0;
}
