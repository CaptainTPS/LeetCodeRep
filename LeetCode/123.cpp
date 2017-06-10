//123. Best Time to Buy and Sell Stock III
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if (prices.size() < 2)
    	{
    		return 0;
    	}
    	std::vector<int> dp(prices.size(), 0);
    	int lowest = prices[0];
    	for (int i = 1; i < prices.size(); ++i)
    	{
    		if (prices[i] < lowest)
    		{
    			lowest = prices[i];
    		}
    		
    		dp[i] = max(prices[i]- lowest, dp[i-1]);
    		
    	}
    	int highest = prices[prices.size() - 1];
    	int re = 0;
    	for (int i = prices.size() - 1; i >=0; --i)
    	{
    		if (prices[i] > highest)
    		{
    			highest = prices[i];
    		}
    		if (highest - prices[i] > 0)
    		{
    			dp[i] += highest - prices[i];
    		}
    		if (dp[i] > re)
    		{
    			re = dp[i];
    		}
    	}
    	return re;
    }
};