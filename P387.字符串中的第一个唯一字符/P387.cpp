#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
		map<char, int> pardonCount;

		int len = s.length();

		for(int i = 0; i < len; ++i){
			char c = s[i];
			if(pardonCount.find(c) == pardonCount.end()){
				pardonCount[c] = 1;
			}
			else{
				++pardonCount[c];
			}
		}

		for(int i = 0; i < len; ++i){
			if(1 == pardonCount[s[i]]){
				return i;
			}
		}

		return -1;
    }
};

int main()
{
	Solution solution;
	
	cout << solution.firstUniqChar("loveleetcode") << endl;

	return 0;
}