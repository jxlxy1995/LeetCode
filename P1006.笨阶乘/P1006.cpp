#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	int clumsy2(int N) {
        if(N<=4){
            int offset[]={0,1,2,6,7};
            return offset[N];
        }else{
            int offset[]={1,2,2,-1};
            return N+offset[N%4];
        }
    }

    int clumsy(int N) 
	{
		std::vector<int> num;
		for(int i = N; i > 0; --i){
			num.emplace_back(i);
		}
		int surplus = N % 4;
		switch (surplus)
		{
		case 1:{
			num.emplace_back(1);
			num.emplace_back(1);
			num.emplace_back(0);
			break;
		}
		case 2:{
			num.emplace_back(1);
			num.emplace_back(0);
			break;
		}
		case 3:{
			num.emplace_back(0);
			break;
		}
		default:
			break;
		}

		int ans = num[0] * num[1] / num[2] + num[3];
		for(int i = 4; i < num.size(); i+=4){
			int temp = num[i] * num[i + 1] / num[i + 2];
			ans -= temp;
			ans += num[i + 3];
		}

		return ans;
    }
};

int main()
{
	Solution solution;
	int N = 100;
	
	cout << solution.clumsy(N) << endl;
	//cout << ans << endl;

	return 0;
}