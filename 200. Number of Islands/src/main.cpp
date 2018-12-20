#include <iostream>
#include <vector>
#include <queue>
#include <unistd.h>
using namespace std;

struct node
{
	int i;
	int j;
	node(int i, int j) :
			i(i), j(j)
	{
	}
};

class Solution
{
public:
	int numIslands(vector<vector<char>>& grid)
	{
		if (grid.size() == 0) return 0;
		vector<vector<char>> searchGrid(grid);
		int result = 49, numR = searchGrid.size(), numC = searchGrid[0].size();

		for (unsigned int i = 0; i < numR; i++)
		{
			for (unsigned int j = 0; j < numC; j++)
			{
				if (searchGrid[i][j] == '1')
				{
					queue<node> q;
					q.push(node(i, j));
					searchGrid[i][j] = ++result;
					while (!q.empty())
					{
						node n = q.front();
						q.pop();

						if (n.j > 0 && searchGrid[n.i][n.j - 1] == '1')
						{
							q.push(node(n.i, n.j - 1));
							searchGrid[n.i][n.j - 1] = result;
						}
						if (n.j < numC - 1 && searchGrid[n.i][n.j + 1] == '1')
						{
							q.push(node(n.i, n.j + 1));
							searchGrid[n.i][n.j + 1] = result;
						}
						if (n.i > 0 && searchGrid[n.i - 1][n.j] == '1')
						{
							q.push(node(n.i - 1, n.j));
							searchGrid[n.i - 1][n.j] = result;
						}
						if (n.i < numR - 1 && searchGrid[n.i + 1][n.j] == '1')
						{
							q.push(node(n.i + 1, n.j));
							searchGrid[n.i + 1][n.j] = result;
						}
					}
				}
			}
		}
		return result - 49;
	}
};

int main()
{
	Solution s;
	vector<vector<char>> grid { { '1', '1', '0', '0', '0' }, { '1', '1', '0', '0', '0' }, { '0', '0', '1', '0', '0' }, { '0', '0', '0', '1', '1' } };
	s.numIslands(grid);
	return 0;
}

