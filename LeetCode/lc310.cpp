#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution310 {
public:

	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		if(n < 3){
            vector<int> t;
            if(n >=2)
                t.push_back(1);
            if(n >= 1)
                t.push_back(0);
            return t;
            
        }
        
        vector<int> cnt(n, 0);
		unordered_multimap<int, int> g;
		for (int i = 0; i < edges.size(); i++)
		{
			g.insert({ edges[i].first, edges[i].second });
			g.insert({ edges[i].second, edges[i].first });
			cnt[edges[i].first]++;
			cnt[edges[i].second]++;
		}

		vector<int> v1, v2, *now, *next, *temp;
		now = &v1;
		next = &v2;
		int total = n;
		for(int i = 0; i< n; i++){
			if(cnt[i] == 1){
				now->push_back(i);
                cnt[i] = 0;
                total--;
			}
		}
		while(total > 2){
			for(int i = 0; i < now->size(); i++){
				auto range = g.equal_range((*now)[i]);
                
				for(auto itr = range.first; itr != range.second; itr++){
					int x = itr->second;
					if(cnt[x] > 0){
						cnt[x]--;
					}
				}
			}
			for(int i = 0; i< n; i++){
				if(cnt[i] == 1){
					next->push_back(i);
                    cnt[i] = 0;
                    total--;
				}
			}
			temp = now; now = next; next = temp; next->clear();

		}
        vector<int> re;
        for(int i = 0; i< n; i++){
            if(cnt[i] > 0)
                re.push_back(i);
        }		
        return re;
		
	}


#if 0
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
#endif
};