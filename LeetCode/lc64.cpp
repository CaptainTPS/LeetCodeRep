#include <cstdlib>
#include <vector>

using std::vector;

int minPathSum(vector<vector<int>>& grid) {
	vector<vector<int>> steps(grid.size(), vector<int>(grid[0].size(), 0));
	steps[0][0] = grid[0][0];
	for (int i = 0; i < steps.size(); i++)
	{
		for (int j = 0; j < steps[i].size(); j++)
		{
			if (j > 0 && i > 0)
			{
				int s = steps[i][j - 1] < steps[i - 1][j] ? steps[i][j - 1] : steps[i - 1][j];
				steps[i][j] = s + grid[i][j];
			}
			else
			{
				if (j > 0){
					steps[i][j] = steps[i][j - 1] + grid[i][j];
				}
				if (i > 0)
				{
					steps[i][j] = steps[i-1][j] + grid[i][j];
				}
			}
		}
	}
	return steps.back().back();
}