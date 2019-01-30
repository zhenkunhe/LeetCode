#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> getRow(int rowIndex)
	{
		vector<vector<int>> res(rowIndex + 1);
		for (int i = 0; i <= rowIndex; i++)
		{
			res[i] = vector<int>(i + 1);
			for (int j = 0; j <= i; j++)
				res[i][j] = (j == 0 || j == i) ? 1 : res[i - 1][j] + res[i - 1][j - 1];
		}
		return res[rowIndex];
	}
};

int main()
{
	Solution s;
	vector<int> res = s.getRow(0);
	for (auto i : res)
	{
		cout << i << "\t";
	}
	cout << endl;
	return 0;
}
