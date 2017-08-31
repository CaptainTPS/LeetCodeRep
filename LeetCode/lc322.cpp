#include <vector>
#include <algorithm>

using namespace std;

class Solution322 {
public:
	typedef long long ll;
	int coinChange(vector<int>& coins, int amount) {
		vector<ll> dp(amount + 1, 1e10);
		dp[0] = 0;
		for (int i = 0; i < coins.size(); i++){
			for (int j = coins[i]; j <= amount; j++){
				dp[j] = min(dp[j], dp[j - coins[i]] + 1);
			}

		}

		if (dp[amount] == 1e10)
			return -1;
		return dp[amount];
	}
};