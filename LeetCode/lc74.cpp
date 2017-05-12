#include <cstdlib>
#include <vector>

using namespace std;

int r;
int c;
int length;

int getRow(int index){
	return index / c;
}

int getCol(int index){
	return index % c;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.empty())
	{
		return false;
	}
	r = matrix.size();
	c = matrix[0].size();
	length = r*c;
	int left = 0;
	int right = length - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int row = getRow(mid);
		int col = getCol(mid);
		if (matrix[row][col] == target)
		{
			return true;
		}
		else if (matrix[row][col] > target)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return false;
}

int main74(){
	int data[3][4] = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 50 } };
	vector<int> row1(data[0], data[0] + 4);
	vector<int> row2(data[1], data[1] + 4);
	vector<int> row3(data[2], data[2] + 4);
	vector<vector<int>> test;
	test.push_back(row1);
	test.push_back(row2);
	test.push_back(row3);
	bool re = searchMatrix(test, 3);
	return 0;
}