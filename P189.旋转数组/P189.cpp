#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		int temp = 0;
        for(int i = k; i < len; ++i){
			temp = nums[i];
			nums[i] = nums[(len + i + k + 1 ) % len];
		}
    }
};

int main()
{
	Solution solution;
	vector<int> nums = {1,2,3,4,5,6,7};
	int k = 3;
	solution.rotate(nums, 3);

	int len = nums.size();
	for(int i = 0; i < len; ++i){
		//cout << (len + ( i + k + 1 )) % len << " ";
		cout << nums[i] << " ";
	}
	cout << endl;

	return 0;
}