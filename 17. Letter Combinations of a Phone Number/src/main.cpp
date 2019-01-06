#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution
{
public:
	vector<string> letterCombinations(string digits)
	{
		vector<string> res, mapPhone = { "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz" };
		queue<string> q;

		for (auto c : mapPhone[digits[0] - '1'])	q.push(string(1, c));

		while (!q.empty())
		{
			string curStr = q.front();
			q.pop();

			if (curStr.size() == digits.size())	res.push_back(curStr);
			else
			{
				string nextStr = mapPhone[digits[curStr.size()] - '1'];
				for (auto c : nextStr)	q.push(curStr + c);
			}

		}
		return res;
	}
};

int main()
{
	Solution s;
	string digits = "2329";
	vector<string> result = s.letterCombinations(digits);
	for (auto i : result)
	{
		cout << i << endl;
	}
	return 0;
}
