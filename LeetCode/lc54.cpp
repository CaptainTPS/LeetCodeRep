#include <cstdlib>
#include <vector>

using namespace std;

int maxl;

void dfs(vector<int>& re, int level, vector<vector<int>>& matrix){
	if (level >= maxl)
	{
		return;
	}
	int x_start = level;
	int x_end = (int)matrix[0].size() - 1 - level;
	int y_start = level;
	int y_end = (int)matrix.size() - 1 - level;
	for (int i = x_start; i < x_end; i++)
	{
		re.push_back(matrix[y_start][i]);
	}
	if (y_start == y_end)
	{
		re.push_back(matrix[y_end][x_end]);
	}
	else
	{
		for (int i = y_start; i < y_end; i++)
		{
			re.push_back(matrix[i][x_end]);
		}
		if (x_start == x_end)
		{
			re.push_back(matrix[y_end][x_end]);
		}
		else
		{
			for (int i = x_end; i > x_start; i--)
			{
				re.push_back(matrix[y_end][i]);
			}
			for (int i = y_end; i > y_start; i--)
			{
				re.push_back(matrix[i][x_start]);
			}
		}
	}
	dfs(re, level + 1, matrix);
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> result;
	if (matrix.empty())
	{
		return result;
	}
	int height = matrix.size();
	int width = matrix[0].size();
	int m = height < width ? height : width;
	maxl = (m + 1) / 2;
	
	dfs(result, 0, matrix);
	return result;
}


int main54(){
	int data[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> t1(data, data + 3);
	vector<int> t2(data + 3, data + 6);
	vector<int> t3(data + 6, data + 9);
	vector<vector<int>> test;
	test.push_back(t1);
	test.push_back(t2);
	test.push_back(t3);
	vector<int> re = spiralOrder(test);
	return 0;
}