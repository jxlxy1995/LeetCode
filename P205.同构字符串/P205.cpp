#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char mapping[256] = {0};
		char mapping2[256] = {0};

		if(s.length() != t.length())
			return false;

		int len = s.length();

		for(int i = 0; i < len; ++i){
			if(0 == mapping[(int)s[i]]){

				if(mapping2[(int)t[i]] != 0 && mapping2[(int)t[i]] != s[i]){
					return false;
				}

				mapping[(int)s[i]] = t[i];
				mapping2[(int)t[i]] = s[i];
			}
			else{
				if(mapping[(int)s[i]] != t[i]){
					return false;
				}
			}
		}

		return true;
    }
};

int main()
{
	Solution solution;
	
	cout << solution.isIsomorphic("egg", "add") << endl;

	return 0;
}