#include <vector>
#include <algorithm>

using namespace std;

class Solution188 {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.empty())
			return 0;

		if (k > prices.size() / 2){
			int profit = 0;
			for (int i = 1; i < prices.size(); i++)
			{
				profit += max(prices[i] - prices[i - 1], 0);
			}
			return profit;
		}

		
		vector<vector<int>> dp(k + 1, vector<int>(prices.size(), 0));
		for (int i = 1; i <= k; i++)
		{
			int debt = dp[i - 1][0] - prices[0];
			for (int j = 1; j < prices.size(); j++)
			{
				/*
				int tmax = 0;
				for (int m = 0; m < j; m++)
				{
					tmax = max(tmax, dp[i - 1][m] + prices[j] - prices[m]);
				}
				*/
				dp[i][j] = max(dp[i][j - 1], prices[j] + debt);
				debt = max(debt, dp[i - 1][j] - prices[j]);
			}
		}

		return dp[k][prices.size() - 1];

	}
};