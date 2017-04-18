#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
	bool flag[10];

	//vertical
	for (int i = 0; i < 9; i++)
	{
		fill(flag, flag + 10, false);
		for (int j = 0; j < 9; j++)
		{
			char temp = board[j][i];
			if (temp == '.')
			{
				continue;
			}
			int index = temp - '0';
			if (flag[index] == false)
			{
				flag[index] = true;
			}
			else
			{
				return false;
			}
		}
	}
	//horizental
	for (int i = 0; i < 9; i++)
	{
		fill(flag, flag + 10, false);
		for (int j = 0; j < 9; j++)
		{
			char temp = board[i][j];
			if (temp == '.')
			{
				continue;
			}
			int index = temp - '0';
			if (flag[index] == false)
			{
				flag[index] = true;
			}
			else
			{
				return false;
			}
		}
	}
	//cube
	int out[3] = { 0, 3, 6 };
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			fill(flag, flag + 10, false);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					char temp = board[out[x] + i][out[y] + j];
					if (temp == '.')
					{
						continue;
					}
					int index = temp - '0';
					if (flag[index] == false)
					{
						flag[index] = true;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}

int main36(){
	string str[9] = { "..4...63.", ".........", "5......9.", "...56....", "4.3.....1", "...7.....", "...5.....", ".........", "........." };
	vector<vector<char>> test;
	for (int i = 0; i < 9; i++)
	{
		vector<char> t;
		for (int j = 0; j < 9; j++)
		{
			t.push_back(str[i][j]);
		}
		test.push_back(t);
	}
	bool re = isValidSudoku(test);
	return 0;
}