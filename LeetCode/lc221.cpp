#include <vector>

using namespace std;

class Solution221 {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty())
			return 0;
		vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
		for (int i = 1; i < matrix.size() + 1; i++)
		{
			for (int j = 1; j < matrix[0].size() + 1; j++)
			{
				if (matrix[i - 1][j - 1] == '1'){
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = 0;
				}
					dp[i][j] += dp[i][j - 1];
					dp[i][j] += dp[i - 1][j];
					dp[i][j] -= dp[i - 1][j - 1];
			}
		}
		int k = 0;
		for (int i = 1; i < dp.size() - k; i++)
		{
			for (int j = 1; j < dp[i].size() - k; j++)
			{
				while (i+k<dp.size() && j+k<dp[0].size() && dp[i + k][j + k] - dp[i+k][j-1] -dp[i-1][j+k] + dp[i-1][j-1] == (k+1)*(k+1))
					k++;
			}
		}
		return k*k;
	}
};