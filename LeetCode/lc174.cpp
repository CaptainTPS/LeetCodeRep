#include <vector>
#include <algorithm>

using namespace std;


class Solution174 {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		typedef long long ll;

		if (dungeon.empty())
			return 0;

		vector<vector<ll>> dp(dungeon.size(), vector<ll>(dungeon[0].size(), 0));

		for (int i = dungeon.size() - 1; i >= 0; i--){
			for (int j = dungeon[i].size() - 1; j >= 0; j--)
			{
				ll temp = INT_MAX;
				if (i != dungeon.size()-1){
					temp = min(temp, dp[i + 1][j]);
				}
				if (j != dungeon[i].size()-1)
					temp = min(temp, dp[i][j + 1]);
				if (temp == INT_MAX)
					temp = 1;

				if (dungeon[i][j] >= temp){
					dp[i][j] = 1;
				}
				else
					dp[i][j] = temp - dungeon[i][j] + 1;
			}
		}

		return dp[0][0];
	}
};