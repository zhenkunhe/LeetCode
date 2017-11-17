#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

class Solution
{
	public:
		int minPatches( vector<int>& nums , int n )
		{
			int OK = 0;
			vector<int> resultAdd;

			vector<int>::iterator find1 = find_if( nums.begin() , nums.end() , [&](int value)
			{
				return (value == 1);
			} );
			if ( find1 == nums.end() ) resultAdd.push_back( 1 );
			else nums.erase( find1 );
			OK = 1;

			while ( OK < n )
			{
				vector<int>::iterator findSmall = find_if( nums.begin() , nums.end() , [&](int value)
				{
					return ((OK+1)>=value);
				} );
				if ( findSmall != nums.end() )
				{
					OK = OK + *findSmall;
					nums.erase( findSmall );
				}
				else
				{
					resultAdd.push_back( OK + 1 );
					OK = (OK + 1) * 2 - 1;
				}
				if ( OK < 0 ) break;
			}
			for (int item : resultAdd)
			{
				cout << item << endl;
			}
			return resultAdd.size();
		}
};

int main()
{
	vector<int> nums;
	nums.push_back( 1 );
	nums.push_back( 2 );
	nums.push_back( 31 );
	nums.push_back( 33 );
	Solution* s = new Solution();
	cout << s->minPatches( nums , 2147483647 ) << endl;
	return 0;
}

