#include <cstdlib>
#include <vector>

using namespace std;

vector<vector<int>> all;

void dfs(vector<int> &one, int n, int k){
	if (n < 0)
	{
		return;
	}
	if (one.size() == k)
	{
		all.push_back(one);
		return;
	}

	dfs(one, n - 1, k);
	one.push_back(n);
	dfs(one, n - 1, k);
	one.pop_back();
}

vector<vector<int>> combine(int n, int k) {
	vector<int> one;
	dfs(one, n, k);
	return all;
}