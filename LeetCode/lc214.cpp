#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

#if 0
//TLE...
class Solution214 {
public:
	string shortestPalindrome(string s) {
		if (s.empty())
			return string();
		int len = 1;
		int maxlen = 0;
		while (len <= s.length()){
			int i = 0, j = len - 1;
			while (i < j){
				if (s[i] != s[j])
					break;
				i++;
				j--;
			}
			if (i >= j){
				maxlen = len;
			}
			len++;
		}
		string re = "";
		for (int i = s.length() - 1; i >maxlen - 1 ; i--)
		{
			re += s[i];
		}
		re += s;
		return re;
	}
};

#endif
class Solution214 {
public:
	int getLen(string s){
		if (s.length() <= 1)
			return 1;
		//kmp
		vector<int> next(s.length(), 0);
		next[0] = -1;
		int i = 0;
		int k = -1;
		while (i <s.length() - 1){
			if (k== -1 || s[i] == s[k]){
				i++;
				k++;
				next[i] = k;
			}
			else{
				k = next[k];
			}
		}
#if 0
		for (auto x : s){
			cout << setw(4) << x;
		}
		cout << endl;
		for(auto x: next){
			cout << setw(4)<< x;
		}
		cout << endl;
#endif	
		return next.back();
	}

	string shortestPalindrome(string s) {
		if (s.empty())
			return string();

		string t = s;
		t += '#';
		for (int i = s.length() - 1; i >= 0; i--)
			t += s[i];
		t += '#';
		int len = getLen(t);

		string re = "";
		for (int i = s.length() - 1; i >len - 1; i--)
		{
			re += s[i];
		}
		re += s;
		return re;
	}

};                      