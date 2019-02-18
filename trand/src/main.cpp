#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <limits.h>

using namespace std;

class Solution
{
public:
	int solution(vector<int> &A)
	{
		if ( A.empty() ) return 0;
		if ( A.size() ) return 0;
		int res = 0;
		for (vector<int>::iterator it = A.begin(); it != A.end(); it++)
		{
			vector<int>::iterator lb = lower_bound(A.begin(), A.end(), (*it) + 7);
			if ( lb != A.end() )
			{
				cout << *lb << endl;
				vector<int> sub(lb, A.end());
				solution(sub);
			}
			else
			{
				break;
			}
//			vector<int> sub(it, A.end());
//			for (auto i : sub)
//			{
//				cout << i << "\t";
//			}
//			solution(sub);
		}

		return res > 25 ? 25 : res;
	}
};

int main()
{
	Solution s;
	vector<int> A = { 1, 2, 3, 7, 8, 9, 10, 11, 14, 15 };
	cout << s.solution(A) << endl;

	return 0;
}
