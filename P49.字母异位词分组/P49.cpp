#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
	{
		unordered_map<string, vector<string>> allStr;
		string temp;
		for(int i = 0; i < strs.size(); ++i){
			temp = strs[i];
			sort(temp.begin(), temp.end());
			allStr[temp].emplace_back(strs[i]);
		}

		vector<vector<string>> ans;
		for(auto iter: allStr){
			ans.emplace_back(move(iter.second));
		}

		return ans;
    }
};

int main()
{
	Solution solution;
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> ans = solution.groupAnagrams(strs);

	for(auto& it1: ans){
		for(auto it2: it1){
			cout << it2 << " ";
		}
		cout << endl;
	}

	return 0;
}