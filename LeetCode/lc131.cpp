//131. Palindrome Partitioning
#include <vector>
#include <string>

using namespace std;

class Solution131 {
public:
	vector<vector<string>> result;

	bool judge(string s){
		if (s.empty())
		{
			return false;
		}
		int left = 0;
		int right = s.length() - 1;
		while (left < right)
		{
			if (s[left] != s[right])
				return false;
			left++; right--;
		}
		return true;
	}

	vector<vector<string>> dfs(string s){
		vector<vector<string>> all;
		if (s.length() == 1)
		{	
			all.push_back(vector<string>(1,s));
			return all;
		}
		if (s.length() == 0)
		{
			all.push_back(vector<string>());
			return all;
		}
		
		for (size_t i = 0; i < s.length(); i++)
		{
			string temp = s.substr(i, s.length() - i);
			if (judge(temp))
			{
				vector<vector<string>> t = dfs(s.substr(0, i));
				for (size_t j = 0; j < t.size(); j++)
				{
					t[j].push_back(temp);
					all.push_back(t[j]);
				}
			}
		}
		return all;
	}

	vector<vector<string>> partition(string s) {
		return dfs(s);
	}
};
