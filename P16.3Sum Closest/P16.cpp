#include <iostream>
#include <string.h>
#include <sstream>
#include <time.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
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
		while (true)
		{
			for (map<int, int>::iterator it1 = appearCount.begin(); it1 != appearCount.end(); ++it1) {
				for (map<int, int>::iterator it2 = it1; it2 != appearCount.end(); ++it2) {
					if (it1 == it2 && it1->second < 2)
						continue;

					int need = closestTarget - (it1->first + it2->first);

					if (need < it2->first)
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

						return closestTarget;
					}
				}
			}

			closestTarget = target + devVal;
			if (devVal > 0) {
				devVal *= -1;
			}
			else {
				devVal *= -1;
				++devVal;
			}
		}
	}
};


void main() 
{
	Solution solution;
	vector<int> nums = { 13,2,0,-14,-20,19,8,-5,-13,-3,20,15,20,5,13,14,-17,-7,12,-6,0,20,-19,-1,-15,-2,8,-2,-9,13,0,-3,-18,-9,-9,-19,17,-14,-19,-4,-16,2,0,9,5,-7,-4,20,18,9,0,12,-1,10,-17,-11,16,-13,-14,-3,0,2,-18,2,8,20,-15,3,-13,-12,-2,-19,11,11,-10,1,1,-10,-2,12,0,17,-19,-7,8,-19,-17,5,-5,-10,8,0,-12,4,19,2,0,12,14,-9,15,7,0,-16,-5,16,-12,0,2,-16,14,18,12,13,5,0,5,6 };
	int ret = solution.threeSumClosest(nums, -59);
	cout << ret << endl;
	getchar();
	getchar();
}