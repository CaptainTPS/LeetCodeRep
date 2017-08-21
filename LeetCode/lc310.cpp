#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxg;

	void dfs(unordered_map<int, int>& g, int now, vector<bool>& flag, vector<int>& cnt){
		flag[now] = true;
		int m = 1e9;
		auto range = g.equal_range(now);
		for (auto i = range.first; i != range.second; i++)
		{
			if (flag[i->second])
				dfs(g, i->second, flag, cnt);
			m = min(m, cnt[i->second] + 1);
		}
		if (m == 1e9)
			m = 0;
		cnt[now] = m;
		maxg = max(maxg, m);
	}

	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		unordered_multimap<int, int> g;
		for (int i = 0; i < edges.size(); i++)
		{
			g.insert({ edges[i].first, edges[i].second });
			g.insert({ edges[i].second, edges[i].first });
		}

		vector<bool> flag(n, false);
		vector<int> cnt(n, 1e9);
		maxg = 0;
		dfs(g, 0,)
	}
};