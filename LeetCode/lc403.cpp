#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool canCross(vector<int>& stones) {
		int n = stones.size();
		if (n <= 1)
			return true;
		if (stones[1] != 1)
			return false;

		unordered_map<int, unordered_set<int>> dp;

		for (auto x : stones){
			dp[x] = unordered_set<int>();
		}

		dp[1].insert(1);
		for (int i = 1; i < n - 1; i++){
			int st = stones[i];
			for (auto j = dp[st].begin(); j != dp[st].end(); j++){
				for (int k = -1; k <= 1; k++){
					int jump = *j + k;
					if (jump <= 0 || dp.find(st+jump) == dp.end())
						continue;
					dp[st + jump].insert(jump);
				}
			}
		}

		return !dp[stones[n - 1]].empty();
	}
};