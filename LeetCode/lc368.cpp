#if 1
class Solution368 {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    	int n = nums.size();
    	if(n <= 1)
    		return nums;
    	vector<int> dp(n, 1);
    	vector<int> traceback(n, -1);
    	sort(nums.begin(), nums.end());

    	for(int i = 0; i< n;i++){
    		int a = nums[i];
    		for(int j = 0; j < i; j++){
    			if(a % nums[j] != 0)
    				continue;

    			int cnt = dp[j] + 1;
    			if(cnt > dp[i]){
    				dp[i] = cnt;
    				traceback[i] = j;
    			}
    		}
    	}
    	int maxindex = 0;
    	for(int i = 0; i < n; i++){
    		if(dp[maxindex] < dp[i])
    			maxindex = i;
    	}

    	vector<int> result;
    	int index = maxindex;
    	while(index != -1){
    		result.push_back(nums[index]);
    		index = traceback[index];
    	}
    	return result;
    }
};

#else


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<int> result;
        dfs(nums, 0, temp, result);
        return result;
    }
private:
	void dfs(vector<int>& n, int now, vector<int>& temp, vector<int>& result){
		if(now >= n.size()){
			if(temp.size() > result.size())
				result = temp;
			return;
		}
		if(temp.size() + n.size() - now <= result.size())
			return;

		int m = -1;
		if(!temp.empty())
			m = temp.back();
		if(m == -1 || n[now] % m == 0){
			temp.push_back(n[now]);
			dfs(n, now+1, temp, result);
			temp.pop_back();
		}
		dfs(n, now+1, temp, result);
	}
};
#endif