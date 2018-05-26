#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int myAtoi(string str) 
	{
		char firstChar;
		int firstPos = 0;
		int neg = 1;
		int ret = 0;
		long long tempRet = 0;
		for (size_t i = 0; i < str.length(); ++i)
		{
			if (' ' == str[i])
			{
				continue;
			}
			firstChar = str[i];
			firstPos = i;
			break;
		}
		if ('+' == firstChar)
		{
			++firstPos;
		}
		else
		{
			if ('-' == firstChar)
			{
				neg = -1;
				++firstPos;
			}
			else if ('0' > firstChar || '9' < firstChar)
			{
				return ret;
			}
		}
		string retStr = "";
		for (int i = firstPos; i < str.length(); ++i)
		{
			if ('0' <= str[i] && '9' >= str[i])
			{
				retStr += str[i];
			}
			else
			{
				break;
			}
		}
		tempRet = atoll(retStr.c_str());
		if (tempRet > INT_MAX)
		{
			if (1 == neg)
			{
				ret = INT_MAX;
			}
			else
			{
				ret = INT_MIN;
			}
		}
		else
		{
			ret = tempRet * neg;
		}
		return ret;
	}
};

int main()
{
	string test = "+95";
	Solution obSolution;
	cout << obSolution.myAtoi(test.c_str()) << endl;
	return 1;
}