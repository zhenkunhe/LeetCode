#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		string result = "";
		if ( strs.size() == 0 ) return result;

		for (unsigned int i = 0; i < strs[0].size(); i++)
		{
			for (string s : strs)
			{
				if ( strs[0][i] != s[i] ) return result;
			}
			result.push_back(strs[0][i]);
		}

		return result;
	}
};

int main()
{
	Solution s;
	vector<string> strs = { "flower", "flo", "flight" };
	cout << s.longestCommonPrefix(strs);

	return 0;
}
