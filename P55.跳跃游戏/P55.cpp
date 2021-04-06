#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
private:
	bool ans;
	vector<int> allnum;
public:
	void Backtrack(int index)
	{
		if(ans) return;
		
		if(allnum[0] >= index){
			ans = true;
			return;
		}

		int start = (index - allnum[index]) > 0 ? (index - allnum[index]) : 0;

		for(int i = start; i < index; ++i){
			Backtrack(i);
			if(ans) return;
		}
	}

    bool canJump2(vector<int>& nums) 
	{
		ans = false;
		int size = nums.size();
		allnum = nums;

		if(size == 0)
			return false;

		if(allnum[0] >= size - 1){
			return true;
		}

		Backtrack(size - 1);

		return ans;
    }

	bool canJump(vector<int>& nums) 
	{
		int k = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > k) return false;
			k = max(k, i + nums[i]);
		}
		return true;
	}

};

int main()
{
	Solution solution;
	vector<int> vec = {2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
	
	cout << solution.canJump(vec) << endl;
	
	return 0;
}