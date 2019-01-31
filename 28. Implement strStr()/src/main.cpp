#include <iostream>
#include <deque>
#include <string>

using namespace std;

class Solution
{
public:
	int strStr(string haystack, string needle)
	{
		if ( needle.empty() ) return 0;
		if ( needle.length() > haystack.length() ) return -1;
		deque<int> q;
		for (int i = 0; i < haystack.length(); i++)
		{
			q.push_back(i);
			for (int j = 0; j < q.size();)
			{
				if ( haystack[q[j]] != needle[j] )
				{
					q.pop_front();
					j = 0;
					continue;
				}
				if ( j == needle.size() - 1 ) return q.front();
				j++;
			}
		}
		return -1;
	}
};

int main()
{
	Solution s;

	string haystack = "abcdef", needle = "cdea";
	cout << s.strStr(haystack, needle) << endl;
	return 0;
}
