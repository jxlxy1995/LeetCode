#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		if (strs.size() == 1)
			return strs[0];
		string ret = findCommonPreFix(strs[0], strs[1]);
		for (size_t i = 2; i < strs.size(); ++i) {
			if (ret.length() == 0)
				break;

			ret = findCommonPreFix(ret, strs[i]);
		}

		return ret;
	}

	string findCommonPreFix(string str1, string str2) {
		int len = str1.length() >= str2.length() ? str2.length() : str1.length();
		string ret = "";
		for (int i = 0; i < len; ++i) {
			if (str1[i] != str2[i]) 
				break;

			ret += str1[i];
		}
		return ret;
	}
};

void main()
{
	vector<string> input = { "flower","flow","flight" };
	Solution solution;
	cout << solution.longestCommonPrefix(input) << endl;
	getchar();
	getchar();
}