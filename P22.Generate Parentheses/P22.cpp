#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	const char* parStr = "()";
	vector<string> generateParenthesis(int n) {
		set<string> strSet;
		strSet.insert(parStr);
		for (int i = 1; i < n; ++i) {
			func(i, strSet);
		}
		
		vector<string> ret;
		for (auto it : strSet) {
			if(it.length() == n * 2)
				ret.push_back(it);
		}
		return ret;
	}

	void func(int n, set<string>& parenthesis) {
		if (0 == n)
			return;

		for (auto it : parenthesis) {
			if(it.length() != n * 2)
				continue;

			for (int i = 1; i <= it.length(); ++i) {
				string tempStr = it;
				tempStr.insert(i, parStr);

				if (parenthesis.find(tempStr) == parenthesis.end())
					parenthesis.insert(tempStr);
			}
		}
	}
};



int main()
{
	Solution solution;
	vector<string> ret = solution.generateParenthesis(2);
	for (auto it : ret) {
		cout << it << endl;
	}
	getchar();
	getchar();
	return 0;
}