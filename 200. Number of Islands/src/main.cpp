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
		int nr = grid.size();
		if (!nr) return 0;
		int nc = grid[0].size();
		int result = 0;

		for (int r = 0; r < nr; r++)
		{
			for (int c = 0; c < nc; c++)
			{
				if (grid[r][c] == '1')
				{
					++result;
					queue<pair<int, int>> q;
					q.push( { r, c });
					grid[r][c] = '0';

					while (!q.empty())
					{
						pair<int, int> rc = q.front();
						q.pop();

						int row = rc.first, col = rc.second;
						if (col > 0 && grid[row][col - 1] == '1')
						{
							q.push( { row, col - 1 });
							grid[row][col - 1] = '0';
						}
						if (col < nc - 1 && grid[row][col + 1] == '1')
						{
							q.push( { row, col + 1 });
							grid[row][col + 1] = '0';
						}
						if (row > 0 && grid[row - 1][col] == '1')
						{
							q.push( { row - 1, col });
							grid[row - 1][col] = '0';
						}
						if (row < nr - 1 && grid[row + 1][col] == '1')
						{
							q.push( { row + 1, col });
							grid[row + 1][col] = '0';
						}
					}
				}
			}//end col
		}//end row
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

