#include <vector>

using namespace std;

class Solution200 {
public:
	vector<pair<int, int>> move;


	void dfs(pair<int,int> now, vector<vector<char>>& grid, vector<vector<bool>> &flag){
		if (now.first < 0 || now.first >= grid.size() || now.second < 0 || now.second >= grid[0].size())
			return;
		
		if (grid[now.first][now.second] == '0' || flag[now.first][now.second])
			return;

		flag[now.first][now.second] = true;
		
		for (int i = 0; i < 4; i++)
		{
			auto to = make_pair<int, int>( now.first + move[i].first, now.second + move[i].second);
			dfs(to, grid, flag);
		}
	}

	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())
			return 0;

		move = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
		vector<vector<bool>> flag(grid.size(), vector<bool>(grid[0].size(), false));

		int cnt = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] != '0' && !flag[i][j]){
					dfs({ i, j }, grid, flag);
					cnt++;
				}
			}
		}
		return cnt;
	}
};