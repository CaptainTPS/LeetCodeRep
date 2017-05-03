#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> result(n, vector<int>(n, 0));
	if (n <=0 )
	{
		return result;
	}
	int cnt = n*n;
	int lx = 0;
	int rx = n - 1;
	int ty = 0;
	int dy = n - 1;

	int index = 1;
	while (index <= cnt)
	{
		for (int i = lx; i <= rx; i++)
		{
			result[ty][i] = index;
			index++;
		}
		ty++;
		for (int i = ty; i <= dy; i++)
		{
			result[i][rx] = index;
			index++;
		}
		rx--;
		for (int i = rx; i >= lx; i--)
		{
			result[dy][i] = index;
			index++;
		}
		dy--;
		for (int i = dy; i >= ty; i--)
		{
			result[i][lx] = index;
			index++;
		}
		lx++;
	}
	return result;
}

int main59(){

	return 0;
}