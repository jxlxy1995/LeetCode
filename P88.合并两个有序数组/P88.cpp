#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

void printfVec(std::vector<int>& vec)
{
    for(auto it: vec){
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
	{
		int i = 0, j = 0;
		list<int> tmp;
		while (i < m && j < n)
		{
			if(nums1[i] < nums2[j]){
				tmp.push_back(nums1[i++]);
			} else{
				tmp.push_back(nums2[j++]);
			}
		}

		while (i < m){
			tmp.push_back(nums1[i++]);
		}
		while (j < n){
			tmp.push_back(nums2[j++]);
		}

		for(int i = 0; i < (m + n); ++i){
			nums1[i] = tmp.front();
			tmp.pop_front();
		}
		
    }
};

int main()
{
	Solution solution;
	vector<int> nums1 = {1,2,3,0,0,0};
	vector<int> nums2 = {2,5,6};
	solution.merge(nums1, 3, nums2, 3);
	printfVec(nums1);
	return 0;
}