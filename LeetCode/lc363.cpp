class Solution363 {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
  		int row = matrix.size();
  		if(row == 0)
  			return 0;
  		int col = matrix[0].size();

      int result = -1e9;
  		for(int left = 0; left < col; left++){
  			vector<int> dp(row, 0);
  			for(int right = left; right < col; right++){
          int prefixSum = 0;
          set<int> pres;
          pres.insert(prefixSum);
          for(int r = 0; r < row; r++){
            dp[r] += matrix[r][right];
            prefixSum += dp[r];

            int target = prefixSum - k;
            auto ptr = lower_bound(pres.begin(), pres.end(), target);
            if(ptr != pres.end()){
              result = max(result, prefixSum - *ptr);
            }

            pres.insert(prefixSum);

          }
  			}
  		}
      return result;      
    }
};