#include <string>

using namespace std;

class Solution394 {
public:
	string dfs(string& s, int& sptr){
		string re = "";
		if (sptr >= s.length())
			return re;
		if (isdigit(s[sptr])){
			int n = 0;
			while (sptr < s.length() && isdigit(s[sptr])){
				n = n * 10 + s[sptr] - '0';
				sptr++;
			}
			string temp;
			sptr++;
			while (sptr < s.length() && s[sptr] != ']'){
				if (isdigit(s[sptr])){
					temp += dfs(s, sptr);
				}
				else
				{
					temp += s[sptr];
					sptr++;
				}
			}
			sptr++;

			for (int i = 0; i < n; i++){
				re += temp;
			}
		}
		return re;
	}

	string decodeString(string s) {
		int ptr = 0;
		string re = "";
		while (ptr < s.length()){
			if (isdigit(s[ptr])){
				re += dfs(s, ptr);
			}
			else
			{
				re += s[ptr];
				ptr++;
			}
		}
		return re;
	}
};