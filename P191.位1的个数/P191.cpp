#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution 
{
private:
	vector<uint32_t> two;

public:
    int hammingWeight(uint32_t n) 
	{
		for(int i = 0; i < 32; ++i){
			two.push_back(pow(2, i));
		}

		int ans = 0;
		for(int i = 0; i < 32; ++i){
			if(n & two[i])
				++ans;
		}

		return ans;
    }
};

int main()
{
	Solution solution;
	uint32_t n = 1;
	cout << solution.hammingWeight(n) << endl;
	return 0;
}