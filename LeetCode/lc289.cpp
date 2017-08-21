#include <vector>

using std::vector;

class Solution289 {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if (board.empty())
			return;

		int row = board.size();
		int col = board[0].size();

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				int cnt = 0;
				for (int m = -1; m <= 1; m++)
				{
					for (int n = -1; n <= 1; n++)
					{
						if (m == 0 && n == 0)
							continue;
						int y = i + m;
						int x = j + n;
						if (x < 0 || x >= col || y < 0 || y >= row)
							continue;
						if (board[y][x] & 1)
							cnt++;
					}
				}
				if (board[i][j] & 1){
					if (cnt == 2 || cnt == 3){
						board[i][j] |= 2;
					}
				}
				else
				{
					if (cnt == 3)
						board[i][j] |= 2;
				}
			}
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (board[i][j] & 2)
					board[i][j] = 1;
				else
					board[i][j] = 0;
			}
		}
	}
};