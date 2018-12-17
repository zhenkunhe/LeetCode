#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		string result;
		cout << result << endl;
		while ()
		{
			for (string s : strs)
			{
				result.push_back(s.);
				cout << s << endl;
				for (int i = 0; i < s.size(); i++)
				{
					cout << s[i] << endl;
					result.push_back(s[i]);
				}
			}
		}

		cout << result << endl;
		return result;
	}
};

int main()
{
	Solution s;
	vector<string> strs;
	strs.push_back("flower");
	strs.push_back("flow");
	strs.push_back("flight");
	s.longestCommonPrefix(strs);

	return 0;
}
