#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	string addBinary(string a, string b)
	{
		string res;
		bool carry = false, da = false, db = false;

		for (string::reverse_iterator it_a = a.rbegin(), it_b = b.rbegin(); it_a != a.rend() || it_b != b.rend();)
		{
			da = it_a != a.rend() ? *it_a++ - '0' : false;
			db = it_b != b.rend() ? *it_b++ - '0' : false;
			res.insert(res.begin(), (!da & !db & carry) | (!da & db & !carry) | (da & db & carry) | (da & !db & !carry) + '0');
			carry = (db & carry) | (db & da) | (da & carry);
		}

		if ( carry ) res.insert(res.begin(), '1');

		return res;
	}
};

int main()
{
	Solution s;

	string a = "11", b = "1";
	cout << s.addBinary(a, b) << endl;
	return 0;
}
