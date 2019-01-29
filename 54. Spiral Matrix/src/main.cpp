#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution
{
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		vector<int> res;
		if ( matrix.size() == 0 ) return res;
		int size_r = matrix.size() - 1;
		int size_c = matrix[0].size() - 1;
		bool b_matrix[size_r][size_c];
		for (int i = 0; i <= size_r; i++)
		{
			for (int j = 0; j <= size_c; j++)
			{
				b_matrix[i][j] = false;
			}
		}

		int r = 0, c = 0, dir = 0;
		res.push_back(matrix[r][c]);
		b_matrix[r][c] = true;
		while (true)
		{
			switch (dir)
			{
			case 0:
				c = c + 1;
				cout  << c << endl;
				cout  << b_matrix[r][c + 1] << endl;
				if ( c == size_c || b_matrix[r][c + 1] ) dir = 1;
				cout  <<  b_matrix[r][c + 1] << endl;
				break;
			case 1:
				r = r + 1;
				cout  << c << endl;
				cout  << b_matrix[r][c + 1] << endl;
				if ( r == size_r || b_matrix[r + 1][c] ) dir = 2;
				cout  <<  b_matrix[r][c + 1] << endl;
				break;
			case 2:
				c = c - 1;
				if ( c == 0 || b_matrix[r][c - 1] ) dir = 3;
				break;
			case 3:
				r = r - 1;
				if ( r == 0 || b_matrix[r - 1][c] ) dir = 0;
				break;
			}

			if ( b_matrix[r][c] ) break;
			res.push_back(matrix[r][c]);
			b_matrix[r][c] = true;
			for (int i = 0; i <= size_r; i++)
			{
				for (int j = 0; j <= size_c; j++)
				{
					cout << b_matrix[i][j] << "\t";
				}
				cout << endl;
			}
			cout << endl;
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
