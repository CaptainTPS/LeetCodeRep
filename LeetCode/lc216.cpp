#include <vector>

using std::vector;


class Solution216 {
public:
	vector<vector<int>> result;

	void dfs(int now, int target, int know, int k, vector<int>& temp){
		if (target == 0 && know == k){
			result.push_back(temp);
			return;
		}
		if (now > target){
			return;
		}
		if (now > 9){
			return;
		}
		if (know > k)
			return;

		temp.push_back(now);
		dfs(now + 1, target - now, know + 1, k, temp);
		temp.pop_back();
		dfs(now + 1, target, know, k, temp);

	}

	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> temp;
		dfs(1, n, 0, k, temp);
		return result;
	}
};