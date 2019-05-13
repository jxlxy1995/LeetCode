#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		vector<int> numVec = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		vector<string> strVec = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		string ret = "";
		for (size_t i = 0; i < numVec.size(); ++i) {
			while (num >= numVec[i]){
				ret += strVec[i];
				num -= numVec[i];
			}
		}
		return ret;
	}
};

int main()
{
	Solution solution;
	int x = 0;
	cin >> x;
	cout << solution.intToRoman(x) << endl;
	getchar();
	getchar();
	return 0;
}
