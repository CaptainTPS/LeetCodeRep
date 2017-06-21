#include <vector>
#include <string>

using namespace std;

#ifdef TLE

class Solution {
public:
	bool dfs(string& s, vector<string>& dic, int index){
		if (index >= s.length()){
			return true;
		}
		bool flag = false;
		for (size_t i = 0; i < dic.size(); i++)
		{
			if (s.substr(index, dic[i].length()).compare(dic[i]) == 0){
				flag |= dfs(s, dic, index + dic[i].length());
			}		
		}
		return flag;
	}

	bool wordBreak(string s, vector<string>& wordDict) {
		return dfs(s, wordDict, 0);
	}
};

#endif

class Solution139 {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.length(), false);
		for (int i = 0; i < s.length(); i++)
		{
			for (size_t j = 0; j < wordDict.size(); j++)
			{
				int n = wordDict[j].length();
				if (i - n  + 1< 0)
					continue;
				if (s.substr(i - n + 1, n).compare(wordDict[j]) == 0){
					if (i - n == -1)
						dp[i] = true;
					else 
						dp[i] = dp[i] || dp[i - n];
				}
				if (dp[i])
					break;
			}
		}
		return dp[s.length() - 1];
	}
};
