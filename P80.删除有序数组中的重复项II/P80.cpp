#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	int removeDuplicates2(vector<int>& nums) {
        if(nums.size() <= 2)    return nums.size();
        int index = 1;
        for(int i = 2; i < nums.size(); i++)
        {
            if(nums[i] != nums[index - 1])
            {
                nums[++index] = nums[i];
            }
        }
        return index + 1;
    }

    int removeDuplicates(vector<int>& nums) 
	{
		if(nums.empty())
			return 0;

		int len = nums.size();

		int lastNum = nums[0];
		int pardon = 1;
		int ans = 1;
		for(auto it = nums.begin() + 1; it != nums.end(); ){
			int temp = *it;
			if(temp == lastNum){
				if(pardon < 2){
					++ans;
					++it;
				} else{
					nums.erase(it);
				}
				++pardon;
			} else{
				lastNum = temp;
				pardon = 1;
				++ans;
				++it;
			}
		}

		return ans;
    }
};

int main()
{
	Solution solution;
	vector<int> nums = {0,0,1,1,1,1,2,3,3};

	cout << solution.removeDuplicates(nums) << endl;

	for(auto it: nums){
		cout << it << " ";
	}
	cout << endl;

	return 0;
}