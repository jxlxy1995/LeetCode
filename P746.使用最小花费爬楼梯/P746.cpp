#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
		int ret = 0;

		int i = -1;
		int len = cost.size();
		
		while (i < len - 2){
			if(cost[i + 1] < cost[i + 2]){
				i += 1;
				ret += cost[i + 1];
			}
			else{
				i += 2;
				ret += cost[i + 2];
			}
		}
		

		return ret;
    }
};

int main()
{
	Solution solution;
	vector<int> cost = {10, 15, 20};
	
	cout << solution.minCostClimbingStairs(cost) << endl;

	return 0;
}