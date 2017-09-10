class Solution85 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row <=0)
            return 0;
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col+1,0));

        for(int i = 0; i< row; i++){
            for(int j = 0; j<col; j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1;
                    if(i >0)
                        dp[i][j] += dp[i-1][j];
                }else
                dp[i][j] = 0;
            }
        }
        int gmax = 0;
        for(int i = 0; i< row; i++){
            vector<int> range;
            for(int j = 0; j<= col; j++){
                while(!range.empty() && dp[i][range.back()] > dp[i][j]){
                    int index = range.back(); range.pop_back();
                    int h = dp[i][index];
                    index = range.empty() ? -1 : range.back();
                    int area = h * (j - index -1);
                    gmax = max(gmax, area);
                }
                range.push_back(j);
            }
        }
        return gmax;

    }
};