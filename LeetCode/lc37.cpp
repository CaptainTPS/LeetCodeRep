#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool isFull(vector<vector<char>>& board, int& x, int& y){
	for (int x_ = 0; x_ < board.size(); x_++)
	{
		for (int y_ = 0; y_ < board[x_].size(); y_++)
		{
			if (board[x_][y_] == '.')
			{
				x = x_;
				y = y_;
				return false;
			}
		}
	}
	return true;
}

bool flag[10];
void allPossibility(vector<vector<char>>& board, int& x, int& y, vector<char>& nums){
	fill(flag, flag + 10, false);
	for (int i = 0; i < 9; i++)
	{
		if (board[i][y] != '.')
		{
			int t = board[i][y] - '0';
			flag[t] = true;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (board[x][i] != '.')
		{
			int t = board[x][i] - '0';
			flag[t] = true;
		}
	}

	int left = (x / 3) * 3;
	int up = (y / 3) * 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[left + i][up + j] != '.')
			{
				int t = board[left + i][up + j] - '0';
				flag[t] = true;
			}
		}
	}

	for (int i = 1; i < 10; i++)
	{
		if (flag[i] == false)
		{
			char c = (char)(i + (int)'0');
			nums.push_back(c);
		}
	}
}

vector<vector<char>> result;

void dfs(vector<vector<char>>& board){
	int x, y;
	if (isFull(board,x,y))
	{
		result = board;
		return;
	}
	vector<char> allp;
	allPossibility(board, x, y, allp);
	if (allp.size() == 0)
	{
		return;
	}
	for (int i = 0; i < allp.size(); i++)
	{
		board[x][y] = allp[i];
		dfs(board);
		board[x][y] = '.';
	}
}

void solveSudoku(vector<vector<char>>& board) {
	dfs(board);
	board = result;
}

int main37(){
	string str[9] = {"987654321", "321987654", "654321987", "798465132", "132798465", "465132798", "879546213", "213879546", "54621387."};
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

	solveSudoku(test);

	return 0;
}