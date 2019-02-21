#include <iostream>
#include <queue>
#include <tree.hpp>

using namespace std;

class Solution
{
public:
	int lenLongestFibSubseq(vector<int>& A)
	{
		int res = 0;
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = i + 1; j < A.size(); j++)
			{
				vector<int> fibs = { A[i], A[j] };
				while (find(A.begin(), A.end(), fibs[fibs.size() - 1] + fibs[fibs.size() - 2]) != A.end())
				{
					fibs.push_back(fibs[fibs.size() - 1] + fibs[fibs.size() - 2]);
				}
				res = fibs.size() > res ? fibs.size() : res;
			}
		}
		return res <= 2 ? 0 : res;
	}
};

int main()
{
	Solution s;
	vector<int> A = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int a = 0xFFFFFFFF;
	cout << (a<<1) << endl;

	return 0;
}
