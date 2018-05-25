#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	string convert(string s, int numRows) 
	{
		int loopN = numRows * 2 - 2;
		if (0 == loopN)
		{
			loopN = 1;
		}
		vector<string> vecRet;
		for (size_t i = 0; i < numRows; ++i)
		{
			vecRet.push_back("");
		}
		for (size_t i = 0; i < s.length();)
		{
			for (int j = 0; j < loopN; ++j,++i)
			{
				if (i >= s.length())
				{
					break;
				}
				if (j < numRows)
				{
					vecRet[j] += s[i];
				}
				else
				{
					//numRows - (2 + j - numRows)
					vecRet[numRows * 2 - 2 - j] += s[i];
				}
			}
		}

		string strRet = "";
		for (int j = 0; j < numRows; ++j)
		{
			strRet += vecRet[j];
		}
		return strRet;
	}
};

int main()
{
	string strInput = "";
	int numRow;
	cin >> strInput;
	cin >> numRow;
	Solution obSolution;
	cout << obSolution.convert(strInput, numRow) << endl;
	cin >> strInput;
	return 0;
}

