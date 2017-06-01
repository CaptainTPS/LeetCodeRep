//87. Scramble String
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool dfs(string& s1, string& s2, int i1start, int i1end, int i2start, int i2end){
		if (i1start>= i1end || i2start>= i2end || i1end - i1start != i2end - i2start)
		{
			return false;
		}
		if (i1end - i1start == 1 &&s1[i1start]==s2[i2start])
		{
			return true;
		}
		vector<int> record(26, 0);
		for (size_t i = i1start; i < i1end; i++)
		{
			record[s1[i] - 'a']++;
		}
		for (size_t i = i2start; i < i2end; i++)
		{
			record[s2[i] - 'a']--;
		}
		for (size_t i = 0; i < record.size(); i++)
		{
			if (record[i] != 0)
			{
				return false;
			}
		}

		bool re = false;
		for (int le = 1; le < i1end - i1start; ++le)
		{	
			re |= dfs(s1, s2, i1start, i1start + le, i2start, i2start + le) && dfs(s1, s2, i1start + le, i1end, i2start + le, i2end);
			re |= dfs(s1, s2, i1start, i1start + le, i2end - le, i2end) && dfs(s1, s2, i1start + le, i1end, i2start, i2end - le);
			if (re)
			{
				break;
			}
		}
		return re;
	}


    bool isScramble(string s1, string s2) {
        return dfs(s1,s2,0,s1.length(), 0, s2.length());
    }
};

int main(){
	string s1 = "abc";
	string s2 = "bca";
	bool re = Solution().isScramble(s1, s2);
	return 0;
}