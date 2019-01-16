#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
using namespace std;

class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int result = 0;
		list<char> strList;

		//遍歷輸入字串
		for (char input : s)
		{
			//如果找到
			if ( find(strList.begin(), strList.end(), input) != strList.end() )
			{
				//從頭找到尾，看第幾個找到的
				for (list<char>::iterator i = strList.begin(); i != strList.end();)
				{
					char data = *i;
					i++;
					strList.pop_front();
					if ( input == data ) break;
				}
			}
			strList.push_back(input);
			if ( strList.size() > result ) result = strList.size();
		}
		return result;
	}
};

class Solution2
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int len = 0, left = 0;
		map<char, int> dict;

		//遍歷輸入字串
		for (int right = 0; right < s.size(); right++)
		{
			if ( dict.find(s[right]) != dict.end() )
			{
				left = max(left, dict[s[right]] + 1);
			}
			dict[s[right]] = right;
			len = max(len, right - left + 1);

		}
		return len;
	}
};

int main()
{
	Solution s;
	string str = "sdvdf";
	cout << s.lengthOfLongestSubstring(str);
	return 0;
}
