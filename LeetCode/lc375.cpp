//lc375
class Solution375 {
public:
    int getMoneyAmount(int n) {
        typedef long long ll;
        vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
        for(int len = 1; len <=n; len++){
        	for(int i = 0; i <= n - len; i++){
        		if(len == 1){
        			dp[i][i+len] = i;
        			continue;
        		}
        		ll lmin = 1e11;
        		for(int j = i + 1; j < i + len; j++){
        			ll lmax = max(dp[i][j - 1], dp[j + 1][i + len]) + j;
        			lmin = min(lmin, lmax);
        		}
        		dp[i][i+len] = lmin;
        	}
        }
        return dp[0][n];
    }
};