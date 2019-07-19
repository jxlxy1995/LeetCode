#include <vector>
#include <string.h>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> rets;
		map<char, vector<string>> keyboard;
		keyboard['2'] = { "a", "b", "c" };
		keyboard['3'] = { "d", "e", "f" };
		keyboard['4'] = { "g", "h", "i" };
		keyboard['5'] = { "j", "k", "l" };
		keyboard['6'] = { "m", "n", "o" };
		keyboard['7'] = { "p", "q", "r", "s" };
		keyboard['8'] = { "t", "u", "v"};
		keyboard['9'] = { "w", "x", "y", "z" };

		getLetters(digits, 0, keyboard, rets);
		return rets;
	}

	void getLetters(string& digits, int pos, map<char, vector<string>>& keyboard, vector<string>& ret) {
		vector<string>& tmpVec = keyboard[digits[pos]];
		vector<string> newRet;
		newRet.clear();
		if (ret.size() == 0) {
			for (int i = 0; i < tmpVec.size(); ++i) {
				ret.push_back(tmpVec[i]);
			}
		}
		else {
			for (int i = 0; i < ret.size(); ++i) {
				for(int j = 0; j < tmpVec.size(); ++j)
					newRet.push_back(ret[i] + tmpVec[j]);
			}
			ret = newRet;
		}

		
		if(pos + 1 < digits.length())
			getLetters(digits, pos + 1, keyboard, ret);
	}
};

void main()
{
	Solution solution;
	vector<string> ret = solution.letterCombinations("23");
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i].c_str() << endl;
	}
	getchar();
	getchar();
}