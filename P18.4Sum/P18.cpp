#include <iostream>
#include <string.h>
#include <sstream>
#include <time.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
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

		int closestTarget = target;
		int devVal = 1;
		map<int, int> needMap;
		for (map<int, int>::iterator it1 = appearCount.begin(); it1 != appearCount.end(); ++it1) {
			for (map<int, int>::iterator it2 = it1; it2 != appearCount.end(); ++it2) {
				for (map<int, int>::iterator it3 = it2; it3 != appearCount.end(); ++it3) {
					if (it1 == it2 && it1->second < 2)
						continue;
					if (it3 == it2 && it2->second < 2)
						continue;
					if (it1 == it2 && it3 == it2 && it1->second < 3)
						continue;

					int need = closestTarget - (it1->first + it2->first + it3->first);

					if (need < it3->first)
						continue;

					if (appearCount.find(need) != appearCount.end()) {
						needMap.clear();
						if (needMap.find(it1->first) != needMap.end()) {
							needMap[it1->first]++;
						}
						else {
							needMap[it1->first] = 1;
						}
						if (needMap.find(it2->first) != needMap.end()) {
							needMap[it2->first]++;
						}
						else {
							needMap[it2->first] = 1;
						}
						if (needMap.find(it3->first) != needMap.end()) {
							needMap[it3->first]++;
						}
						else {
							needMap[it3->first] = 1;
						}
						if (needMap.find(need) != needMap.end()) {
							needMap[need]++;
						}
						else {
							needMap[need] = 1;
						}

						bool flag = true;
						for (map<int, int>::iterator itTmp = needMap.begin(); itTmp != needMap.end(); ++itTmp) {
							if (itTmp->second > appearCount[itTmp->first]) {
								flag = false;
								break;
							}
						}

						if (flag) {
							tmp.clear();
							tmp.push_back(it1->first);
							tmp.push_back(it2->first);
							tmp.push_back(it3->first);
							tmp.push_back(need);

							ret.push_back(tmp);
						}
					}
				}
			}
		}
		return ret;
	}
};


void main()
{
	Solution solution;
	vector<int> nums = { 1, 0, -1, 0, -2, 2 };
	vector<vector<int>> ret = solution.fourSum(nums, 0);

	for (size_t i = 0; i < ret.size(); ++i) {
		for (size_t j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	getchar();
	getchar();
}