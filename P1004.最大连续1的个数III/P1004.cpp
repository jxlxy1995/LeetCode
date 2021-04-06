#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	int posFunc(vector<int>& A, int k, int pos)
	{
		int ans = 0;
		int re = 0;
		int len = A.size();
		for(int i = pos; i < len; ++i){
			if(0 == A[i]){
				++re;
			}

			if(re > k)
				break;

			++ans;
		}

		return ans;
	}

    int longestOnes(vector<int>& A, int K) 
	{
		int len = A.size();
		vector<int> ret(len, 0);
		
		int t = posFunc(A, K, 0);
		ret[0] = t;
		int longest = t;

		for(int i = 1; i < len; ++i){
			if(1 == A[i - 1]){
				ret[i] = ret[i - 1] - 1;
				continue;
			}

			t = posFunc(A, 1, i);
			ret[i] = t + ret[i - 1] - 1;

			if(ret[i] > longest)
				longest = ret[i];
			
			if(longest >= len - 1)
				break;
		}

		return longest;
    }
};

int main()
{
	Solution solution;
	vector<int> A = {1,1,1,0,0,0,1,1,1,1,0};
	int k = 2;

	cout << solution.longestOnes(A, k) << endl;

	return 0;
}