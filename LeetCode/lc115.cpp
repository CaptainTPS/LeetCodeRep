#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

#ifdef  TimeLimitExceeded

class Solution115 {
public:
	string s1, s2;
	int cnt;
	void dfs(int n, string now){
		if (now.compare(s2) == 0)
		{
			cnt++;
			return;
		}
		if (now.length() >= s2.length())
		{
			return;
		}
		if (now.compare(0, now.length(), s2, 0, now.length()) != 0)
		{
			return;
		}
		if (n >= s1.length())
		{
			return;
		}

		now.push_back(s1[n]);
		dfs(n + 1, now);
		now.pop_back();
		dfs(n + 1, now);
	}

	int numDistinct(string s, string t) {
		s1 = s;
		s2 = t;
		cnt = 0;
		string now;
		dfs(0, now);
		return cnt;
	}
};
#endif

class Solution115 {
public:
	int numDistinct(string s, string t) {
		vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, 0));
		for (size_t i = 0; i < s.length() + 1; i++)
		{
			dp[i][0] = 1;
		}
		for (size_t i = 1; i <= s.length(); i++)
		{
			for (size_t j = 1; j <= t.length(); j++)
			{
				if (s[i - 1] == t[j - 1])
				{
					dp[i][j] += dp[i - 1][j - 1];
				}
				dp[i][j] += dp[i - 1][j];
			}
		}
		return dp[s.length()][t.length()];
	}
};
