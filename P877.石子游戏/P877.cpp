#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
		int playerA = 0;
		int playerB = 0;
		int turn = 0;
		int lp = 0, rp = piles.size() - 1;

		while (lp <= rp)
		{
			if(lp == rp){
				playerB += piles[lp];
				break;
			}

			int leftDiff = piles[lp] - piles[lp + 1];
			int rightDiff = piles[rp] - piles[rp - 1];
			int addValue = 0;
			if(rightDiff > leftDiff){
				addValue = piles[rp];
				--rp;
			}
			else{
				addValue = piles[lp];
				++lp;
			}

			if(turn % 2 == 0)
				playerA += addValue;
			else
				playerB += addValue;

			++turn;
		}
		
		return playerA > playerB;
    }
};

int main()
{
	Solution solution;
	vector<int> piles = {6,3,9,9,3,8,8,7};
	
	cout << solution.stoneGame(piles) << endl;

	getchar();

	return 0;
}