//377. Combination Sum IV
class Solution377 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        comb = vector<int>(target + 1, -1);
        comb[0] = 1;
        dfs(nums, target);
        return comb[target];
    }

private:
	vector<int> comb;
	int dfs(vector<int>& nums, int target){
		if(comb[target] >=0)
			return comb[target];
		
		int ptr = 0;
		int cnt = 0;
		while(ptr < nums.size() && nums[ptr] <= target){
			cnt += dfs(nums, target - nums[ptr]);
			ptr++;
		}
		comb[target] = cnt;
		return cnt;
	}
};