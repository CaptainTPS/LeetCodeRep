//130. Surrounded Regions
#include <cstdlib>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution130 {
public:
	vector<vector<int>> flags;

	struct pos
	{
		int x, y;
		pos(int x_, int y_){
			x = x_;
			y = y_;
		}
	};

	void bfs(vector<vector<char>>& b){
		queue<pos> now;
		for (size_t i = 0; i < b.size(); i++)
		{
			if (b[i][0] == 'O')
			{
				now.push(pos(0, i));
			}
			if (b[i][b[0].size() - 1] == 'O')
			{
				now.push(pos(b[0].size() - 1, i));
			}
		}
		for (size_t i = 0; i < b[0].size(); i++)
		{
			if (b[0][i] == 'O')
			{
				now.push(pos(i, 0));
			}
			if (b[b.size() -1][i] == 'O')
			{
				now.push(pos(i, b.size() - 1));
			}
		}
		
		while (!now.empty())
		{
			pos n = now.front();
			now.pop();
			flags[n.y][n.x] = 1;
			for (int xt = -1; xt <= 1; xt++)
			{
				if (n.x + xt >= 0 && n.x + xt < b[n.y].size() && b[n.y][n.x + xt] == 'O' && flags[n.y][n.x + xt] == 0)
					now.push(pos(n.x + xt, n.y));
			}
			for (int yt = -1; yt <= 1; yt++)
			{
				if (n.y + yt >= 0 && n.y + yt < b.size() && b[n.y + yt][n.x] == 'O' && flags[n.y + yt][n.x] == 0)
					now.push(pos(n.x, n.y + yt));
			}
		}
	}

	void solve(vector<vector<char>>& board) {
		if (board.empty())
		{
			return;
		}
		flags = vector<vector<int>>(board.size(), vector<int>(board[0].size(), 0));
		bfs(board);
		for (size_t y = 0; y < board.size(); y++)
		{
			for (size_t x = 0; x < board[y].size(); x++)
			{
				if (flags[y][x] == 0 && board[y][x] == 'O')
				{
					board[y][x] = 'X';
				}
			}
		}
	}
};