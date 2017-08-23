#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

class Solution332 {
public:
	vector<string> route;

	void dfs(string now, map<string, multiset<string>>& iti){
		while (!iti[now].empty()){
			auto f = iti[now].begin();
			string next = *f;
			iti[now].erase(f);
			dfs(next, iti);
		}
		route.push_back(now);
	}

	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		map<string, multiset<string>> iti;
		string start = "JFK";
		
		for (auto x : tickets){
			iti[x.first].insert( x.second );
		}

		dfs(start, iti);

		vector<string> result(route.rbegin(), route.rend());
		
		return result;
	}
};