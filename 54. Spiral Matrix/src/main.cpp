#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution
{
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		vector<int> res;
		if ( matrix.size() == 0 ) return res;
		int m = matrix.size() - 1, n = matrix[0].size() - 1;
		bool trav[m + 1][n + 1];
		memset(trav, false, sizeof(bool) * (m + 1) * (n + 1));

		int r = 0, c = 0;
		int dir = (c == n) ? 1 : 0;

		while (r <= m && r >= 0 && c <= n && c >= 0 && !trav[r][c])
		{
			res.push_back(matrix[r][c]);
			trav[r][c] = true;
			if ( dir == 0 && (++c >= n || trav[r][c + 1]) ) ++dir %= 4;
			else if ( dir == 1 && (++r >= m || trav[r + 1][c]) ) ++dir %= 4;
			else if ( dir == 2 && (--c <= 0 || trav[r][c - 1]) ) ++dir %= 4;
			else if ( dir == 3 && (--r <= 0 || trav[r - 1][c]) ) ++dir %= 4;
		}
		return res;
	}
};

class Solution2
{
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		vector<int> res;
		if ( matrix.empty() ) return res;
		int m = matrix.size(), n = matrix[0].size();
		int u = 0, d = m - 1, l = 0, r = n - 1;
		while (true)
		{
			// up
			for (int col = l; col <= r; col++)
				res.push_back(matrix[u][col]);
			if ( ++u > d ) break;
			// right
			for (int row = u; row <= d; row++)
				res.push_back(matrix[row][r]);
			if ( --r < l ) break;
			// down
			for (int col = r; col >= l; col--)
				res.push_back(matrix[d][col]);
			if ( --d < u ) break;
			// left
			for (int row = d; row >= u; row--)
				res.push_back(matrix[row][l]);
			if ( ++l > r ) break;
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> matrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	vector<int> res = s.spiralOrder(matrix);
	for (auto i : res)
	{
		cout << i << "\t";
	}
	cout << endl;

	return 0;
}
