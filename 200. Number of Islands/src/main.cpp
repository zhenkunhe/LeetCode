#include <iostream>
#include <vector>
#include <queue>
#include <unistd.h>
using namespace std;

class Solution
{
public:
	int numIslands(vector<vector<char>>& grid)
	{
		if ( grid.empty() ) return 0;
		int n = grid[0].size() - 1, m = grid.size() - 1, result = 0;

		for (int r = 0; r <= m; r++)
		{
			for (int c = 0; c <= n; c++)
			{
				if ( grid[r][c] == '1' )
				{
					++result;
					queue<pair<int, int>> q;
					q.push( { r, c });
					grid[r][c] = '0';

					while (!q.empty())
					{
						pair<int, int> front = q.front();
						q.pop();

						int r = front.first, c = front.second;
						if ( c > 0 && grid[r][c - 1] == '1' )
						{
							q.push( { r, c - 1 });
							grid[r][c - 1] = '0';
						}
						if ( c < n && grid[r][c + 1] == '1' )
						{
							q.push( { r, c + 1 });
							grid[r][c + 1] = '0';
						}
						if ( r > 0 && grid[r - 1][c] == '1' )
						{
							q.push( { r - 1, c });
							grid[r - 1][c] = '0';
						}
						if ( r < m && grid[r + 1][c] == '1' )
						{
							q.push( { r + 1, c });
							grid[r + 1][c] = '0';
						}
					}
				}
			} //end col
		} //end row
		return result;
	}
};

int main()
{
	Solution s;
	vector<vector<char>> grid { { '1', '1', '0', '0', '0' }, { '1', '1', '0', '0', '0' }, { '0', '0', '1', '0', '0' }, { '0', '0', '0', '1', '1' } };
	s.numIslands(grid);
	return 0;
}

