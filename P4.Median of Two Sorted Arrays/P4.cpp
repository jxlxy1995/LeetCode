#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		size_t size1 = nums1.size();
		size_t size2 = nums2.size();
		int targetPos1 = -1, targetPos2 = -1;
		int targetNum1 = 0, targetNum2 = 0;
		double ret;

		int totalSize = size1 + size2;
		targetPos1 = totalSize / 2;
		if (totalSize % 2 == 0)
		{
			targetPos2 = targetPos1 - 1;
		}
		int i = 0, j = 0;
		int tempMin;
		if (nums1.size() == 0 && nums2.size() == 0)
		{
			return 0.00f;
		}

		if (nums1.size() > 0 && nums2.size() > 0)
		{
			if (nums1[0] < nums2[0])
			{
				tempMin = nums1[0];
				++i;
			}
			else
			{
				tempMin = nums2[0];
				++j;
			}
		}
		else
		{
			if (0 == nums1.size())
			{
				tempMin = nums2[0];
				++j;
			}
			else if(0 == nums2.size())
			{
				tempMin = nums1[0];
				++i;
			}
		}
		for (int k = 1;; ++k)
		{
			if (k - 1 == targetPos1)
			{
				targetNum1 = tempMin;
			}
			if (k - 1 == targetPos2)
			{
				targetNum2 = tempMin;
			}
			if (k > targetPos1)
			{
				break;
			}

			if (i >= nums1.size())
			{
				tempMin = nums2[j];
				++j;
				continue;
			}
			if (j >= nums2.size())
			{
				tempMin = nums1[i];
				++i;
				continue;
			}


			if (nums1[i] < nums2[j])
			{
				tempMin = nums1[i];
				++i;
			}
			else
			{
				tempMin = nums2[j];
				++j;
			}
		}
		if (-1 != targetPos2)
		{
			ret =(double) (targetNum1 + targetNum2) / 2.00f;
		}
		else
		{
			ret = (double)targetNum1;
		}
		return ret;
	}
};

int main()
{
	Solution obSolution;
	vector<int> num1, num2;
// 	num1.push_back(1);
// 	num1.push_back(2);
// 	num2.push_back(3);
//	num2.push_back(1);
	double ret = obSolution.findMedianSortedArrays(num1, num2);
	cout << ret << endl;
	getchar();
	getchar();
	return 0;
}