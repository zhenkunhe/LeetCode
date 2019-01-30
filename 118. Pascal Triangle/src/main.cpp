#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> res(numRows);
		for (int i = 0; i < numRows; i++)
		{
			res[i] = vector<int>(i + 1);
			for (int j = 0; j <= i; j++)
				res[i][j] = (j == 0 || j == i) ? 1 : res[i - 1][j] + res[i - 1][j - 1];
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> res = s.generate(5);
	for (auto i : res)
	{
		for (auto j : i)
		{
			cout << j << "\t";
		}
		cout << endl;
	}

	return 0;
}
