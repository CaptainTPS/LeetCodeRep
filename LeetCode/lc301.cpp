#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution301 {
public:
	unordered_set<string> result;

	void dfs(string now, string s, int index, int left, int right, int pair){
		if (index >= s.length() && left == 0 && right == 0 && pair == 0){
			result.insert(now);
			return;
		}
		if (index >= s.length())
			return;

		if (s[index] != '(' && s[index] != ')'){
			dfs(now+s[index], s, index + 1, left, right, pair);
		}
		else if (s[index] == '('){
			if (left >0 )
				dfs(now, s, index + 1, left - 1, right, pair);
			dfs(now + s[index], s, index + 1, left, right, pair + 1);
		}
		else if (s[index] == ')'){
			if (pair > 0){
				dfs(now + s[index], s, index + 1, left, right, pair - 1);
			}
			if (right > 0){
				dfs(now, s, index + 1, left, right - 1, pair);
			}
		}
	}

	vector<string> removeInvalidParentheses(string s) {
		int left = 0;
		int right = 0;
		for (auto x : s){
			if (x == '('){
				left++;
			}
			else if (x ==')')
			{
				if (left > 0)
					left--;
				else
					right++;
			}
			else
			{
				continue;
			}
		}

		dfs("", s, 0, left, right, 0);

		vector<string> re(result.begin(), result.end());

		return re;


	}
};