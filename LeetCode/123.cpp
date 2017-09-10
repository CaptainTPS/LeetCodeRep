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

#if 0
//another state machin
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
        {
            return 0;
        }
    int n = prices.size();
    int minal = -1e9;
    vector<int> init(n + 1, 0);
    vector<int> hold1(n + 1, minal);
    vector<int> sell1(n + 1, minal);
    vector<int> hold2(n + 1, minal);
    vector<int> terminal(n + 1, minal);

    for(int i = 1; i<=n; i++){
        int p = prices[i-1];
        hold1[i] = max(hold1[i-1], init[i-1] - p);
        sell1[i] = max(sell1[i-1], hold1[i-1] + p);
        hold2[i] = max(hold2[i-1], sell1[i-1] - p);
    terminal[i] = max(terminal[i-1], max(hold1[i-1] + p, hold2[i-1] + p));
}
if(terminal[n] < 0)
    return 0;
return terminal[n];
}
};

#endif