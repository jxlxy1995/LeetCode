#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int reverse(int x)
	{
		bool neg = false;
		if (x < 0)
		{
			x *= -1;
			neg = true;
		}
		// 		char temp[256];
		// 		sprintf_s(temp, 256, "%d", x);
		string reverseStr = "";
		string srcStr = to_string(x);
		for (int i = srcStr.length() - 1; i >= 0; --i)
		{
			reverseStr += srcStr[i];
		}
		long long tempRet = atoll(reverseStr.c_str());
		if (tempRet > INT_MAX)
		{
			tempRet = 0;
		}
		int ret = tempRet;
		if (neg)
		{
			ret *= -1;
		}
		return ret;
	}
	bool isPalindrome(int x) {
		int y = reverse(x);
		if (x < 0 || y != x)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

int main()
{
	Solution obSolution;
	cout << obSolution.isPalindrome(10) << endl;
	return 0;
}