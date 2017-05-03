#include <cstdlib>
#include <vector>

using std::vector;

//not work now
int calC(int down, int top){
	long long re = 1;
	long long cnt = down;
	while (cnt > down - top)
	{
		re *= cnt;
		cnt--;
	}
	cnt = 1;
	while (cnt<=top)
	{
		re /= cnt;
		cnt++;
	}
	return re;
}

int uniquePathsWithObstacles1(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	if (m <=0)
	{
		return 0;
	}
	int n = obstacleGrid[0].size();

	int down = m - 1 + n - 1;
	int top = m < n ? m - 1 : n - 1;
	int all = calC(down, top);

	int cm, cn;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (obstacleGrid[i][j] == 1)
			{
				cm = i;
				cn = j;
				down = cm + cn;
				top = cm < cn ? cm : cn;
				int notwork = calC(down, top);

				down = m - 1 - cm + n - 1 - cn;
				top = m - cm < n - cn ? m - cm - 1 : n - cn - 1;
				notwork *= calC(down, top);
				all = all - notwork;
			}
		}
	}

	if (all < 0)
	{
		all = 0;
	}
	return all;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	vector<vector<int>> step(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
	if (obstacleGrid[0][0] == 0)
	{
		step[0][0] = 1;
	}
	for (int i = 0; i < step.size(); i++)
	{
		for (int j = 0; j < step[i].size(); j++)
		{
			if (obstacleGrid[i][j] == 1)
			{
				continue;
			}
			if (i > 0)
			{
				step[i][j] += step[i - 1][j];
			}
			if (j > 0)
			{
				step[i][j] += step[i][j - 1];
			}
		}
	}

	return step.back().back();
}

int main63(){
	vector<vector<int>> ob(1, vector<int>(1, 0));
	ob[0][0] = 1;
	int re = uniquePathsWithObstacles(ob);
	return 0;
}