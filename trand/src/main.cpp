#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <limits.h>

using namespace std;

class Solution
{
public:
	int solution(vector<int> &A)
	{
		if ( A.empty() ) return 0;
		int res = 25;
		for (int i = 0; i < A.size(); i++)
		{
			vector<int>::iterator lb = lower_bound(A.begin(), A.end(), A[i] + 7);
			if ( lb != A.end() )
			{
				cout << "i=" << i << "\t";
				cout << "A[i]=" << A[i] << "\t";
				cout << "*lb=" << *lb << "\t";

				vector<int> sub(lb, A.end());
				for (auto j : sub)
				{
					cout << j << "\t";
				}
				cout << endl;
				int sub_res = solution(sub) + 2 * i + 7;
				cout << sub_res << endl;
				res = sub_res < res ? sub_res : res;
			}
			else
			{
//				vector<int> sub(find(A.begin(), A.end(), A[i]), A.end());
//				for (auto j : sub)
//				{
//					cout << j << "\t";
//				}
//				cout << endl;
//				int sub_res = (sub.size() >= 4) ? 2 * i + 7 : 2 * sub.size();
				int sub_size = A.size() - i;
				int sub_res = (2 * i) + ((sub_size >= 4) ? 7 : 2 * sub_size);
				cout << sub_res << endl;
				res = sub_res < res ? sub_res : res;
				break;
			}
		}

		return res;
	}
};

int main()
{
	Solution s;
	vector<int> A = { 2, 3, 7, 8, 9, 10, 11, 14, 15};
	cout << s.solution(A) << endl;

	return 0;
}
