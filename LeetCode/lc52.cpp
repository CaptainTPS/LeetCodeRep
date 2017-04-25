#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

namespace lc52{

	struct point
	{
		int x, y;
		point(int x_, int y_){
			x = x_;
			y = y_;
		}
	};

	vector<vector<string>> allre;

	int cnt;

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
		point tp = p;
		while (tp.x < flags.size())
		{
			flags[tp.x][p.y] = false;
			tp.x++;
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
			cnt++;
			return;
		}

		for (int i = 0; i < n; i++)
		{
			if (flags[now][i])
			{
				vector<vector<bool>> tempcopy(flags);
				setflag(flags, point(now, i));
				re.push_back(point(now, i));
				dfs(re, n, flags);
				re.pop_back();
				flags = tempcopy;
			}
		}
	}

	int totalNQueens(int n) {
		cnt = 0;
		vector<bool> f(n, true);
		vector<vector<bool>> flag(n, f);
		vector<point> init;
		dfs(init, n, flag);
		return cnt;
	}

	
}

int main52(){
	int t = lc52::totalNQueens(4);
	cout << t;
	return 0;
}