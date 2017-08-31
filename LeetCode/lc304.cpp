#include <vector>

using namespace std;

class NumMatrix {
public:
	NumMatrix(vector<vector<int>> matrix) {
		int rows = matrix.size();
		if (rows == 0)
			return;
		int cols = matrix[0].size();
		presum = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));

		for (int i = 1; i <= rows; i++){
			for (int j = 1; j <= cols; j++){
				presum[i][j] = matrix[i - 1][j - 1] + presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int re = presum[row2 + 1][col2 + 1] - presum[row2 + 1][col1] - presum[row1][col2 + 1] + presum[row1][col1];
		return re;
	}

private:
	vector<vector<int>> presum;
};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix obj = new NumMatrix(matrix);
* int param_1 = obj.sumRegion(row1,col1,row2,col2);
*/