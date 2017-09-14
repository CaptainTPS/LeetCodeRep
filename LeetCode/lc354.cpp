class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if(n == 0)
        	return 0;
        vector<int> dp(n, 1);
        sort(envelopes.begin(), envelopes.end(), less<pair<int,int>>());
        int gmax = 1;
        for(int i = 0; i< n; i++){
        	for(int j = 0; j<i; j++){
        		if(iswork(envelopes[i],envelopes[j]))
        			dp[i] = max(dp[i], dp[j]+1);
        	}
        	gmax = max(gmax, dp[i]);

        }
        return gmax;
    }

private:
	bool iswork(pair<int, int>& out, pair<int, int>& in){
		if(out.first > in.first && out.second > in.second)
			return true;
		return false;
	}
};