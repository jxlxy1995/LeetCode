#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

class Solution 
{
public:
    uint32_t reverseBits(uint32_t n) 
	{
		bitset<32> temp(n);
		string ansStr = temp.to_string();
		reverse(ansStr.begin(),ansStr.end());
		bitset<32> temp2(ansStr);
		uint32_t ans = temp2.to_ulong();
		return ans;
    }
};

int main()
{
	Solution solution;
	uint32_t in = 43261596;
	cout << solution.reverseBits(in) << endl;
	return 0;
}