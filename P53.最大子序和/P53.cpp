#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
	{
		int size = nums.size();
		if(0 == size)
			return 0;

		vector<int> maxSum;
		maxSum.resize(size, 0);
		maxSum[0] = nums[0]; 
		int ans = maxSum[0];
		for(int i = 1; i < size; ++i){
			maxSum[i] = max(nums[i], maxSum[i - 1] + nums[i]);
			if(maxSum[i] > ans)
				ans = maxSum[i];
		}

		return ans;
    }
};

int main()
{
	Solution solution;
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

	cout << solution.maxSubArray(nums) << endl;

	return 0;
}