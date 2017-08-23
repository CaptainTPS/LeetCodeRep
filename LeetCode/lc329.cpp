#include <vector>
#include <algorithm>

using namespace std;

class Solution329 {
public:
	vector<vector<int>> dp;

	int dfs(int y, int x, vector<vector<int>>& matrix){
		if (dp[y][x])
			return dp[y][x];

		int m = 0;
		if (y - 1 >= 0 && matrix[y - 1][x] > matrix[y][x]){
			m = max(m, dfs(y - 1, x, matrix));
		}
		if (y + 1 < matrix.size() && matrix[y + 1][x] > matrix[y][x]){
			m = max(m, dfs(y + 1, x, matrix));
		}
		if (x - 1 >= 0 && matrix[y][x - 1] > matrix[y][x]){
			m = max(m, dfs(y, x - 1, matrix));
		}
		if (x + 1 < matrix[0].size() && matrix[y][x + 1] > matrix[y][x]){
			m = max(m, dfs(y, x + 1, matrix));
		}
		dp[y][x] = m + 1;
		return m + 1;
	}

	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int rows = matrix.size();
		if (rows == 0)
			return 0;
		int cols = matrix[0].size();

		dp = vector<vector<int>>(rows, vector<int>(cols, 0));

		int m = 0;
		for (int row = 0; row < rows; row++){
			for (int col = 0; col < cols; col++){
				m = max(m, dfs(row, col, matrix));
			}
		}
		return m;
	}
};