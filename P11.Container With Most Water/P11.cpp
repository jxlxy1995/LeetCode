#include <iostream>
#include <vector>
#define min(a,b) (((a) < (b)) ? (a) : (b))

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxVal = 0;
		int i = 0;
		int j = height.size() - 1;
		int val = 0;
		for (;;)
		{
			if (i >= j)
				break;

			val = (j - i) * min(height[i], height[j]);
			if (val > maxVal)
				maxVal = val;
			if (height[i] > height[j])
			{
				--j;
			}
			else
			{
				++i;
			}
		}

		return maxVal;
	}
};

int main()
{
	int a[7] = { 2,3,4,5,18,17,6 };
	vector<int> h;
	h.insert(h.begin(), a, a + 7);
	Solution obSolution;
	cout << obSolution.maxArea(h) << endl;
	getchar();
	getchar();
	return 0;
}