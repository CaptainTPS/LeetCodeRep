//121. Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int profit = 0;
    	if (prices.empty())
    	{
    		return profit;
    	}
    	int lowest = prices[0];
    	for (int i = 0; i < prices.size(); ++i)
    	{
    		if (prices[i] < lowest)
    		{
    			lowest = prices[i];
    		}
    		if (prices[i] - lowest > profit)
    		{
    			profit = prices[i] - lowest;
    		}
    	}
    	return profit;    
    }
};