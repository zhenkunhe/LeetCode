#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K)
    {
    	int result = 0;
    	int size = A.size();

		for (int i = K; i <= size; i++)
		{
			int left = 0, right = i-1;
			for (int j = 0; j < size-i+1; j++)
			{
		    	set<int> s;
				for(int k=left;k<=right;k++)
				{
					s.insert(A[k]);
				}
//				cout <<left <<" "<< right << " ";
//				cout << "  " << s.size();
				if(s.size() == K) result++;
				left++;
				right++;
			}

//			cout << endl;
		}

		return result;
    }
};

int main()
{
	Solution s;

	vector<int> A = {2,1,2,1,2};
	cout << s.subarraysWithKDistinct(A, 2) << endl;

	return 0;
}
