#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

vector<string> all;

void dfs(int lnow, int total, int n, string temp){
	if (lnow == n && total >= 0)
	{
		while (total > 0)
		{
			temp += ')';
			total--;
		}
		all.push_back(temp);
		return;
	}

	if (total > 0)
	{
		temp += ')';
		total--;
		dfs(lnow, total, n, temp);
		total++;
		temp.pop_back();
		
	}
	temp += '(';
	total++;
	lnow++;
	dfs(lnow, total, n, temp);
	temp.pop_back();
	total--;
	lnow--;
}

vector<string> generateParenthesis(int n) {
	all.clear();
	if (n == 0)
	{
		return all;
	}
	dfs(1, 1, n, "(");
	return all;
}

int main22(){
	vector<string> t = generateParenthesis(3);
	return 0;
}