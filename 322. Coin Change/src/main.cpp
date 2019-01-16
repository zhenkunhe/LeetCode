#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution
{
public:
	int coinChange(vector<int>& coins, int amount)
	{
		int result[amount + 1] = { -1 };
		result[0] = 0;
		for (int i = 1; i <= amount; i++)
		{
			int min = INT_MAX;
			for (auto coin : coins)
			{
				int preIndex = i - coin;
				if ( preIndex >= 0 && result[preIndex] != -1 && result[preIndex] < min ) min = result[preIndex];
			}
			result[i] = (min == INT_MAX) ? -1 : min + 1;
		}

		return result[amount];
	}
};

class Solution2
{
public:
	int coinChange(vector<int>& coins, int amount)
	{
		sort(coins.rbegin(), coins.rend());
		int min = INT_MAX;
		coinChange(coins, amount, 0, 0, min);
		return min == INT_MAX ? -1 : min;
	}
private:
	void coinChange(vector<int>& coins, int amount, int count, int index, int& res)
	{
		if ( amount == 0 )
		{
			if ( count < res ) res = count;
			return;
		}
		if ( index == coins.size() ) return;

		for (int k = amount / coins[index]; k >= 0 && count + k < res; k--)
			coinChange(coins, amount - k * coins[index], count + k, index + 1, res);
	}
};

int main()
{
	Solution s;
	vector<int> coins { 1, 2, 5 };
	int amount = 11;
	cout << s.coinChange(coins, amount);
	return 0;
}
