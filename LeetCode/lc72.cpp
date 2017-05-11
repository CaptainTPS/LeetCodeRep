#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int minDistance(string word1, string word2) {
	vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, 0));
	for (int i = 0; i < word1.length() + 1; i++)
	{
		dp[i][0] = i;
	}
	for (int i = 0; i < word2.length() + 1; i++)
	{
		dp[0][i] = i;
	}

	for (int i = 1; i < word1.length()+1; i++)
	{
		for (int j = 1; j < word2.length()+1; j++)
		{
			int a = dp[i - 1][j] + 1;
			int b = dp[i][j - 1] + 1;
			int c;
			if (word1[i-1] == word2[j-1])
			{
				c = dp[i - 1][j - 1];
			}
			else
			{
				c = dp[i - 1][j - 1] + 1;
			}
			dp[i][j] = min<int>(min<int>(a, b), c);
		}
	}
	return dp.back().back();
}