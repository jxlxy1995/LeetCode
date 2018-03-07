#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> vecRet;
		bool bFind = false;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			for (size_t j = i + 1; j < nums.size(); ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					vecRet.push_back(i);
					vecRet.push_back(j);
					bFind = true;
					break;
				}
			}
			if (bFind)
			{
				break;
			}
		}
		return vecRet;
	}
};

void main()
{
	Solution obSolution;
	vector<int> a;
	vector<int> b = { 2, 7, 11, 15 };
	int target = 9;
	a = obSolution.twoSum(b, target);
	cout << a[0] << a[1] <<endl;
	getchar();
	getchar();
}