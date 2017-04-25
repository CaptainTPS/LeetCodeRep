#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string, vector<string>> all;
	sort(strs.begin(), strs.end());

	for (int i = 0; i < strs.size(); i++)
	{
		string temp = strs[i];
		sort(temp.begin(), temp.end());
		auto finder = all.find(temp);
		if (finder == all.end())
		{
			vector<string> t;
			t.push_back(strs[i]);
			all.insert(unordered_map<string, vector<string>>::value_type(temp, t));
		}
		else
		{
			finder->second.push_back(strs[i]);
		}
	}
	vector<vector<string>> ttt;
	for (auto iter = all.begin(); iter != all.end(); iter++)
	{
		ttt.push_back(iter->second);
	}
	return ttt;
}

int main49(){

	return 0;
}