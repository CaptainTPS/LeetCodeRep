class Solution279 {
public:
    int numSquares(int n) {
 
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
        	int sq = sqrt(i);
        	if(i == sq * sq){
        		dp[i] = 1;
        		continue;
        	}
        	int m = 1e10;
        	for (int j = 1; j <= sq; ++j)
        	{
        		m = min(m , dp[i - j*j]);
        	}
        	dp[i] = m + 1;
        }
        return dp[n];
    }
};