class Solution363 {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
  		int row = matrix.size();
  		if(row == 0)
  			return 0;
  		int col = matrix[0].size();

  		for(int left = 0; left < col; left++){
  			vector<int> dp(row, 0);
  			for(int right = left; right < col; right++){

  			}
  		}      
    }
};