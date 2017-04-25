#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct point
{
	int x, y;
	point(int x_, int y_){
		x = x_;
		y = y_;
	}
};

vector<vector<string>> allre;

void storeResult(vector<point>& re, int n){
	vector<string> temp;
	for (int i = 0; i < n; i++)
	{
		string t = "";
		for (int j = 0; j < n; j++)
		{
			t += '.';
		}
		temp.push_back(t);
	}

	for (int i = 0; i < re.size(); i++)
	{
		temp[re[i].x][re[i].y] = 'Q';
	}

	allre.push_back(temp);

}

void setflag(vector<vector<bool>>& flags, point p){
	point tp(0,0);
	while (tp.x < flags.size())
	{
		flags[tp.x][p.y] = false;
		tp.x++;
	}
	while (tp.y<flags.size())
	{
		flags[p.x][tp.y] = false;
		tp.y++;
	}
	tp = p;
	while (tp.x >=0 && tp.y >=0 && tp.x < flags.size() & tp.y < flags.size())
	{
		flags[tp.x][tp.y] = false;
		tp.y--;
		tp.x--;
	}
	tp = p;
	while (tp.x >= 0 && tp.y >= 0 && tp.x < flags.size() & tp.y < flags.size())
	{
		flags[tp.x][tp.y] = false;
		tp.y++;
		tp.x--;
	}
	tp = p;
	while (tp.x >= 0 && tp.y >= 0 && tp.x < flags.size() & tp.y < flags.size())
	{
		flags[tp.x][tp.y] = false;
		tp.y++;
		tp.x++;
	}
	tp = p;
	while (tp.x >= 0 && tp.y >= 0 && tp.x < flags.size() & tp.y < flags.size())
	{
		flags[tp.x][tp.y] = false;
		tp.y--;
		tp.x++;
	}

}

void dfs(vector<point>& re, int n, vector<vector<bool>>& flags){
	int now = (int)re.size();
	if (now == n)
	{
		storeResult(re,n);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (flags[now][i])
		{
			vector<vector<bool>> tempcopy(flags);
			setflag(flags, point(now,i));
			re.push_back(point(now, i));
			dfs(re, n, flags);
			re.pop_back();
			flags = tempcopy;
		}
	}
}

vector<vector<string>> solveNQueens(int n) {
	vector<bool> f(n, true);
	vector<vector<bool>> flag(n, f);
	vector<point> init;
	dfs(init, n, flag);
	return allre;
}

ostream& operator<<(ostream& c, vector<string> t){

	for (int i = 0; i < t.size(); i++)
	{
		c << t[i] << endl;
	}
	return c;
}

int main51(){
	vector<vector<string>> t;
	t = solveNQueens(4);
	for (int i = 0; i < t.size(); i++)
	{
		cout << t[i] << endl << endl;
	}
	return 0;
}