#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
class Solution 
{
public:
	//利用栈的思想求解
	int trap3(vector<int>& height)
	{
		int ans = 0, current = 0;
		stack<int> st;
		while (current < height.size()) {
			while (!st.empty() && height[current] > height[st.top()]) {
				int top = st.top();
				st.pop();
				if (st.empty())
					break;
				int distance = current - st.top() - 1;
				int bounded_height = min(height[current], height[st.top()]) - height[top];
				ans += distance * bounded_height;
			}
			st.push(current++);
		}
		return ans;
	}

	//优化原始解法，存储每个位置左边右边最大值
	int trap2(vector<int>& height)
	{
		if (height.empty())
			return 0;
		int ans = 0;
		int size = height.size();
		vector<int> left_max(size), right_max(size);
		left_max[0] = height[0];
		for (int i = 1; i < size; i++) {
			left_max[i] = max(height[i], left_max[i - 1]);
		}
		right_max[size - 1] = height[size - 1];
		for (int i = size - 2; i >= 0; i--) {
			right_max[i] = max(height[i], right_max[i + 1]);
		}
		for (int i = 1; i < size - 1; i++) { 
			ans += min(left_max[i], right_max[i]) - height[i];
		}
		return ans;
	}

	//原始解法
    int trap0(vector<int>& height)
	{
		int ans = 0;
		int size = height.size();

		for (int i = 1; i < size - 1; i++) {
			int max_left = 0, max_right = 0;
			//找左边最大值
			for (int j = i; j >= 0; j--) {
				max_left = max(max_left, height[j]);
			}
			//找右边最大值
			for (int j = i; j < size; j++) {
				max_right = max(max_right, height[j]);
			}
			ans += min(max_left, max_right) - height[i];
		}
		return ans;
	}

	//双指针解法
	int trap(vector<int>& height)
	{
		if (height.empty())
			return 0;
		
		int ans = 0;
		int leftPtr = 0;
		int rightPtr = height.size() - 1;
		int leftMax = 0, rightMax = 0;

		while(leftPtr < rightPtr){
			if(height[leftPtr] <= height[rightPtr]){

				if(height[leftPtr] < leftMax)
					ans += leftMax - height[leftPtr];
				else
					leftMax = height[leftPtr];

				++leftPtr;
			} else{
				if(height[rightPtr] < rightMax)
					ans += rightMax - height[rightPtr];
				else
					rightMax = height[rightPtr];

				--rightPtr;
			}
		}

		return ans;
	}
};


int main()
{
	Solution solution;
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

	cout << solution.trap0(height) << endl;

	int ans = solution.trap(height);
	cout << ans << endl;
	
	return 0;
}