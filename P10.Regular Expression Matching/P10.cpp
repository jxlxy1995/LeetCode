#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		if (s == p) 
		{
			return true;
		}
		if ("" == p) 
		{
			return false;
		}
		str = s;
		pattern = p;
		return match(0, 0);
	}

	bool match(int index1, int index2)
	{
		bool last1 = index1 >= str.length();
		bool last2 = index2 >= pattern.length();

		if (last1 && last2)
		{
			return true;
		}
		if (!last1 && last2)
		{
			return false;
		}

		//带*的情况
		if (index2 + 1 < pattern.length() && '*' == pattern[index2 + 1])
		{
			if (last1)
			{
				return match(index1, index2 + 2);
			}

			if (str[index1] == pattern[index2] || pattern[index2] == '.')
			{
				return match(index1 + 1, index2) || match(index1, index2 + 2);
			}
			else
			{
				return match(index1, index2 + 2);
			}
		}

		if (last1 && !last2)
		{
			return false;
		}

		//不带*的情况
		if (str[index1] == pattern[index2] || '.' == pattern[index2])
		{
			return match(index1 + 1, index2 + 1);
		}
		return false;
	}

private:
	string str = "";
	string pattern = "";
};

int main()
{
	string s="", p="c*.*i";
	cin >> s;
	cin >> p;
	Solution obSolution;
	cout << obSolution.isMatch(s, p) << endl;
	getchar();
	getchar();
	return 0;
}