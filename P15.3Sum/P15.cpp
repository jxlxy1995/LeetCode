#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <map>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		vector<int> tmp;
		map<int, int> appearCount;
		for (size_t i = 0; i < nums.size(); ++i) {
			if (appearCount.find(nums[i]) == appearCount.end()) {
				appearCount[nums[i]] = 1;
			}
			else {
				++appearCount[nums[i]];
			}
		}

		for (map<int, int>::iterator it1 = appearCount.begin(); it1 != appearCount.end(); ++it1) {
			if (it1->first > 0)
				break;

			for (map<int, int>::iterator it2 = it1; it2 != appearCount.end(); ++it2) {
				if (it1 == it2 && it1->second < 2)
					continue;

				int need = -1 * (it1->first + it2->first);

				if(need < it2->first)
					continue;

				if (appearCount.find(need) != appearCount.end()) {
					if (need == it1->first || need == it2->first) {
						if (appearCount[need] < 2)
							continue;
					}
					if (need == it1->first && need == it2->first) {
						if (appearCount[need] < 3)
							continue;
					}

					tmp.clear();
					tmp.push_back(it1->first);
					tmp.push_back(it2->first);
					tmp.push_back(need);
					
					ret.push_back(tmp);
					
				}
			}
		}

		return ret;
	}

	bool canPush(vector<vector<int>>& vec, vector<int>& tmp) {
		vector<int> tmp2;
		unordered_set<int> pool;
		int count = 0;
		bool b1 = allZero(tmp);
		bool b2;
		for (size_t i = 0; i < vec.size(); ++i) {
			tmp2.clear();
			pool.clear();
			//count = 0;

			tmp2 = vec[i];

			b2 = allZero(tmp2);

			if(b1 != b2)
				continue;

			for (size_t j = 0; j < tmp2.size(); ++j) {
				pool.insert(tmp2[j]);
			}

			for (size_t j = 0; j < tmp.size(); ++j) {
				if (pool.find(tmp[j]) != pool.end())
				{
					//++count;
					pool.erase(tmp[j]);
				}
			}

			if (0 == pool.size())
				return false;
		}

		return true;
	}

	bool allZero(vector<int>& tmp) {
		for (size_t i = 0; i < tmp.size(); ++i) {
			if (tmp[i] != 0) {
				return false;
			}
		}
		return true;
	}
};

void main()
{
	vector<int> input = { 11,3,13,-14,12,-13,14,-7,-1,14,5,-15,-11,-15,9,11,-6,-11,-15,-5,-3,5,-7,10,11,11,-10,-3,-4,8,-15,-15,-4,6,8,-6,8,7,-6,-8,6,6,-8,11,-1,8,-1,8,13,-1,-11,-5,-11,-3,12,8,-15,-13,-10,-11,3,12,11,14,3,4,-15,-4,-4,-13,-5,9,8,2,-3,-8,-12,12,-14,-14,-12,12,-12,-7,-14,8,8,9,10,13,13,-10,2,9,-10,-9,-10,12,2,1,14,13,-13,8,-8,0,7,-5,-11,0,-12,-8,-11,-8,-8,-9,-15,-15 };
	//vector<int> input = { 0, 0 };
	Solution solution;
	vector<vector<int>> ret = solution.threeSum(input);
	vector<int> tmp;
	for (size_t i = 0; i < ret.size(); ++i) {
		tmp = ret[i];
		for (size_t j = 0; j < tmp.size(); ++j) {
			cout << tmp[j] << " ";
		}
		cout <<  endl;
	}

// 	map<int, int> appearCount;
// 	for (size_t i = 0; i < input.size(); ++i) {
// 		if (appearCount.find(input[i]) == appearCount.end()) {
// 			appearCount[input[i]] = 1;
// 		}
// 		else {
// 			++appearCount[input[i]];
// 		}
// 	}
// 
// 	for (auto it : appearCount) {
// 		cout << it.first << " " << it.second << endl;
// 	}
	getchar();
	getchar();
}