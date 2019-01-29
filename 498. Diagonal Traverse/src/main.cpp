#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
	{
		vector<int> res;
		if(matrix.size()==0) return res;
		int size_r = matrix.size() - 1;
		int size_c = matrix[0].size() - 1;
		for (int i = 0; i <= size_r + size_c; i++)
		{
			if ( i % 2 )
			{
				for (int c = size_c; c >= 0; c--)
				{
					int r = i - c;
					if ( 0 <= r && r <= size_r ) res.push_back(matrix[r][c]);
				}
			}
			else
			{
				for (int r = size_r; r >= 0; r--)
				{
					int c = i - r;
					if ( 0 <= c && c <= size_c ) res.push_back(matrix[r][c]);
				}
			}
		}
		return res;
	}
};
int main()
{
	Solution s;
	vector<vector<int>> matrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	vector<int> res = s.findDiagonalOrder(matrix);
	for (auto i : res)
	{
		cout << i << "\t";
	}
	cout << endl;

	return 0;
}
