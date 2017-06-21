#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
#ifdef TLE
class Solution132 {
public:
	bool judge(const string& s){
		int left = 0;
		int right = s.length() - 1;
		while (left < right){
			if (s[left] != s[right])
			{
				return false;
			}
			left++;
			right--;
		}
		return true;
	}

	int minCut(string s) {
		set<int> pos1, pos2, *now, *next, *t;
		now = &pos1;
		next = &pos2;
		now->insert(0);
		int cnt = 0;
		if (judge(s))
			return cnt;
		do
		{
			cnt++;
			for (auto itr : *now){
				for (int i = itr + 1; i < s.length(); i++)
				{
					if (judge(s.substr(itr, i - itr))){
						if (judge(s.substr(i, s.length() - i))){
							return cnt;
						}
						else
						{
							next->insert(i);
						}
					}
				}
			}
			now->clear();
			t = now;
			now = next;
			next = t;

		} while (1);
		return 0;
	}
	
};
#endif

class Solution132 {
public:
	int minCut(string s) {
		if (s.empty())
		{
			return 0;
		}

		vector<vector<bool>> isPal(s.length() + 1, vector<bool>(s.length() + 1, false));
		vector<int> minCut(s.length() + 1, -1);
		int k = 0;
		for (int i = s.length() -1; i >= 0; i--)
		{
			minCut[i] = k++;
		}
		for (int i = s.length() -1; i >= 0; i--)
		{
			for (int j = i; j <= s.length() -1; j++)
			{
				if (s[i]==s[j] && (j - i <=1 || isPal[i+1][j-1]))
				{
					isPal[i][j] = true;
				}
				if (isPal[i][j]){
					minCut[i] = min(minCut[i], minCut[j + 1] + 1);
				}
			}
		}
		return minCut[0];
	}
};

#if 0
int main(){
	string t = "aa";
	Solution132().minCut(t);
	return 0;
}
#endif