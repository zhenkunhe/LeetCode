#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		stack<char> stack;
		for (auto c : s)
		{
			if (c == ')')
			{
				if (stack.empty() || stack.top() != '(') return false;
				stack.pop();
			}
			else if (c == ']')
			{
				if (stack.empty() || stack.top() != '[') return false;
				stack.pop();
			}
			else if (c == '}')
			{
				if (stack.empty() || stack.top() != '{') return false;
				stack.pop();
			}
			else stack.push(c);
		}
		return stack.empty() ? true : false;
	}
};

class Solution2
{
public:
	Solution2()
	{
		mappings[')'] = '(';
		mappings[']'] = '[';
		mappings['}'] = '{';
	}
	bool isValid(string s)
	{
		stack<char> stack;
		for (auto c : s)
		{
			if (mappings.count(c))
			{
				if (stack.empty() || stack.top() != mappings[c]) return false;
				stack.pop();
			}
			else stack.push(c);
		}

		return stack.empty() ? true : false;
	}
private:
	map<char, char> mappings;
};

int main()
{
	Solution2 s;
	string str = "[]]";
	s.isValid(str);
	return 0;
}
