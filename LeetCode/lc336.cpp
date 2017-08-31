#include <set>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution336 {
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		unordered_map<string, int> rev;
		unordered_map<string, int> ori;
		for (auto x : words){
			static int cnt = 0;
			ori.insert({ x, cnt });
			reverse(x.begin(), x.end());
			rev.insert({ x, cnt });
			cnt++;
		}

		set<pair<int, int>> result;

		for (int i = 0; i < words.size(); i++){
			for (int len = 0; len <= words[i].length(); len++){
				string temp = words[i].substr(0, len);
				string remain = words[i].substr(len, words[i].length() - len);
				if (!isPali(remain))
					continue;
				auto finder = rev.find(temp);
				if (finder != rev.end() && i != finder->second){
					result.insert({ i, finder->second });
					if (len == 0){
						result.insert({ finder->second, i });
					}
				}
			}
		}
		for (auto itr = rev.begin(); itr != rev.end(); itr++){
			string now = itr->first;
			for (int len = 0; len <= now.length(); len++){
				string temp = now.substr(0, len);
				string remain = now.substr(len, now.length() - len);
				if (!isPali(remain))
					continue;
				int i = itr->second;
				auto finder = ori.find(temp);
				if (finder != ori.end() && i != finder->second){
					result.insert({ finder->second, i });
					if (len == 0){
						result.insert({i,  finder->second });
					}
				}
			}
		}
		
		vector<vector<int>> re;
		for (auto itr = result.begin(); itr != result.end(); itr++){
			re.push_back({ itr->first, itr->second });
		}

		return re;
	}

private:
	bool isPali(string& s){
		int left = 0;
		int right = s.length();
		right -= 1;
		while (left < right)
			if (s[left++] != s[right--]){
				return false;
			}
		return true;
	}
};