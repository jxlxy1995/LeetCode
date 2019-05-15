#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		vector<int> numVec = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		vector<string> strVec = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		int ret = 0;
		for (size_t i = 0; i < numVec.size(); ++i) {
			while (true){
				string tmp = s;
				string tmp2 = tmp.substr(0, strVec[i].length());

				if(tmp2 != strVec[i])
					break;

				s = tmp.substr(strVec[i].size(), s.length() - 1);
				ret += numVec[i];
			}
		}

		return ret;
	}

	int romanToInt2(string s) {
		vector<int> num;
		num.push_back(0);
		for (int i = s.length() - 1, j = 0; i >= 0; i--, j++)
			//for (int i = 0;i < s.length(); i++)  
		{
			int t;
			switch (s[i])
			{
			case 'I':
				t = 1;
				t = t < abs(num[j]) ? -t : t;
				num.push_back(t);
				break;

			case 'V':
				t = 5;
				t = t < abs(num[j]) ? -t : t;
				num.push_back(t);
				break;

			case 'X':
				t = 10;
				t = t < abs(num[j]) ? -t : t;
				num.push_back(t);
				break;

			case 'L':
				t = 50;
				t = t < abs(num[j]) ? -t : t;
				num.push_back(t);
				break;

			case 'C':
				t = 100;
				t = t < abs(num[j]) ? -t : t;
				num.push_back(t);
				break;

			case 'D':
				t = 500;
				t = t < abs(num[j]) ? -t : t;
				num.push_back(t);
				break;

			case 'M':
				t = 1000;
				t = t < abs(num[j]) ? -t : t;
				num.push_back(t);
				break;

			}
		}

		int ret = 0;
		for (int i : num)
		{
			ret += i;
		}

		return ret;
	}
};

int main()
{
	Solution solution;
	string input;
	cin >> input;
	cout << solution.romanToInt2(input) << endl;

	getchar();
	getchar();
}