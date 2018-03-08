#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution 
{
public:
	int lengthOfLongestSubstring(string s) 
	{
		string strSub = "";
		int nSLen = s.length();
		int nLen = 0;
		if (nSLen > 0)
		{
			nLen = 1;
		}
		for (size_t i = 0; i < nSLen; ++i)
		{
			set<int> setUsed;
			setUsed.insert(s[i]);
			for (size_t j = i + 1; j < nSLen; ++j)
			{
				if (nLen >= (nSLen - i))
				{
					break;
				}
				if (setUsed.find(s[j]) != setUsed.end())
				{
					break;
				}
				setUsed.insert(s[j]);
				if (nLen < (j - i + 1))
				{
					nLen = j - i + 1;
				}
			}
		}
		return nLen;
	}
};

void main()
{
	string s = "abcabcd";
	Solution obSolution;
	cout << obSolution.lengthOfLongestSubstring(s) << endl;
	getchar();
	getchar();
}