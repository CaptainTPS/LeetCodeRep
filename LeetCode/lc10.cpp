#include <cstdlib>
#include <string>
#include <regex>
#include <iostream>

using namespace std;

#if 0
//a better dp solution
class Solution {
public:
	bool isMatch(string s, string p) {
		vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length()));
		dp[0][0] = true;
		for(int i = 1; i<=s.length(); i++){
			dp[i][0] = false;
		}
		dp[0][1] = false;
		for(int i = 2; i<= p.length(); i++){
			if(p[i-1] == ‘*’){
				dp[0][i] = dp[0][i-2];
			}else
			dp[0][i] = false;
		}

		for(int i = 1; i<=s.length(); i++){
			for(int j = 1; j <= p.length() ; j++){
				if(p[j-1] == ‘*’){
					dp[i][j] = dp[i][j-2] || ((s[i-1] = p[j-2]  || p[j-1] ==’.’ ) && dp[i-1][j]);
				}else{
					dp[i][j] = (p[j-1]==s[i-1] || p[j-1] ==’.’) && dp[i-1][j-1];
				}
			}
		}
		return dp[s.length()][p.length()];
	}
};

#endif



bool isMatchCheat(string s, string p) {
	regex expression(p);

	bool t = regex_match(s, expression);
	return t;
}

bool isMatch(string s, string p) {
	if (s.empty())
	{
		if (p.empty())
		{
			return true;
		}
		else if (p.size()== 1)
		{
			return false;
		}
		else if (p[1] != '*')
		{
			return false;
		}
		else{
			p.erase(p.begin(), p.begin() + 2);
			return isMatch(s, p);
		}
	}
	else{
		if (p.empty())
		{
			return false;
		}
		else if (p.size() == 1)
		{
			if (p[0] == '.')
			{
				p[0] = s[0];
			}

			if (p[0] == s[0])
			{
				s.erase(s.begin());
				p.erase(p.begin());
				return isMatch(s, p);
			}
			else
			{
				return false;
			}
		}
		else if (p[1] != '*')
		{
			if (p[0] == '.')
			{
				p[0] = s[0];
			}

			if (p[0] == s[0])
			{
				s.erase(s.begin());
				p.erase(p.begin());
				return isMatch(s, p);
			}
			else
			{
				return false;
			}
		}
		else{
			string tp = p;
			tp.erase(tp.begin(), tp.begin() + 2);
			if (isMatch(s,tp))
			{
				return true;
			}
			while (!s.empty())
			{
				if (s[0] != p[0]&& p[0] !='.')
				{
					break;
				}
				s.erase(s.begin());
				if (isMatch(s,tp))
				{
					return true;
				}
			}
			return false;
		}
	}
}

int main10(){
	string str = "aaaa";
	string pattern = "a*a";
	
	bool t = isMatch(str, pattern);

	cout << t << endl;
	
	return 0;
}