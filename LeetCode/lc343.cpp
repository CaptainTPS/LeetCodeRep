#include <vector>
#include <algorithm>

using namespace std;

class Solution343 {
public:
	int integerBreak(int n) {
		if (n == 1)
			return 0;
		vector<int> dp(n+1, 0);
		dp[1] = 1;
		for (int i = 2; i <= n; i++){
			int maxn = 1;
			for (int j = 1; j <= i / 2; j++){
				maxn = max(maxn, dp[j] * dp[i - j]);
			}
			if (i != n){
				dp[i] = max(i, maxn);
			}
			else
			{
				dp[i] = maxn;
			}
		}

		return dp[n];

	}
};