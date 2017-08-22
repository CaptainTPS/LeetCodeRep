#include <vector>
#include <algorithm>

using namespace std;

class Solution312 {
public:
	int maxCoins(vector<int>& nums) {
		int len = nums.size();
		if (len == 0){
			return 0;
		}
		vector<vector<int>> dp(len + 2, vector<int>(len + 2, 0));
		nums.insert(nums.begin(), 1);
		nums.insert(nums.end(), 1);
		for (int le = 1; le <= len; le++){
			for (int start = 1; start + le - 1 <= len; start++){
				int end = start + le - 1;
				int maxcoin = 0;
				for (int last = start; last <= end; last++){
					int coin = dp[start][last - 1] + dp[last + 1][end];
					coin += nums[start - 1] * nums[last] * nums[end + 1];
					maxcoin = max(coin, maxcoin);
				}
				dp[start][end] = maxcoin;
			}
		}

		return dp[1][len];
	}
};