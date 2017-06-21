#include <vector>
#include <string>

using namespace std;

class Solution140 {
public:
	vector<vector<string>> dp;
	vector<string> result;

	void dfs(int index, string s){
		if (index < 0){
			s.pop_back();
			result.push_back(s);
			return;
		}

		for (size_t i = 0; i < dp[index].size(); i++)
		{
			dfs(index - dp[index][i].length(), dp[index][i] + " " + s);
		}
	}

	vector<string> wordBreak(string s, vector<string>& wordDict) {
		dp = vector<vector<string>>(s.length(), vector<string>());

		for (int i = 0; i < s.length(); i++)
		{
			for (size_t j = 0; j < wordDict.size(); j++)
			{
				int n = wordDict[j].length();
				if (i - n +1 <0)
					continue;

				if (s.substr(i - n + 1, n).compare(wordDict[j]) == 0){
					if (i - n == -1)
						dp[i].push_back(wordDict[j]);
					else{
						if (!dp[i - n].empty())
							dp[i].push_back(wordDict[j]);
					}
				}
			}
		}

		dfs(s.length() - 1, "");
		return result;
	}
};
