#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	int fa[201] = {0};
	int rank[201] = {0};

	int find(int x){
		if(x == fa[x])
			return x;
		else{
			fa[x] = find(fa[x]);  //父节点设为根节点
			return fa[x];         //返回父节点
		}
	}

	void merge(int i, int j){
		int x = find(i), y = find(j);    //先找到两个根节点
		if (rank[x] <= rank[y])
			fa[x] = y;
		else
			fa[y] = x;
		if (rank[x] == rank[y] && x != y)
			++rank[y];                   //如果深度相同且根节点不同，则新的根节点的深度+1
	}

    int findCircleNum(vector<vector<int>>& isConnected) 
	{
		
		for(int i = 0; i < 201; ++i){
			fa[i] = i;
			rank[i] = 1;
		}

		int n = isConnected.size();

		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(1 == isConnected[i][j]){
					merge(i, j);
				}
			}
		}
		
		set<int> allCircle;
		for(int i = 0; i < n; ++i){
			fa[i] = find(i);

			if(allCircle.find(fa[i]) == allCircle.end()){
				allCircle.insert(fa[i]);
			}
		}

		int ans = allCircle.size();
		return ans;
    }
};

int main()
{
	Solution solution;
	vector<vector<int>> isConnected = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
	
	cout << solution.findCircleNum(isConnected) << endl;

	return 0;
}