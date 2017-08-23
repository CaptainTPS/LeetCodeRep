#include <string>
#include <vector>

using namespace std;

class Solution316{
public:
	string  removeDuplicateLetters(string s){
		int n = s.length();
		if (n <= 1)
			return s;
		
		vector<bool> mask(n, true);

		int loc = 0;
		int preloc = loc;
		while (loc < n)
		{
			vector<int> dup(26, 0);
			for (int i = loc; i < n; i++){
				char x = s[i];
				dup[x - 'a']++;
			}

			for (int i = loc; i < n; i++){
				if (mask[i] == false)
					continue;
				if (s[i] < s[loc])
					loc = i;
				if (--dup[s[i] - 'a'] == 0)
					break;
			}

			for (int i = preloc; i < loc; i++){
				mask[i] = false;
			}
			for (int i = loc + 1; i < n; i++){
				if (s[i] == s[loc])
					mask[i] = false;
			}
			while (mask[++loc] == false);
			preloc = loc;
		}

		string re;
		for (int i = 0; i < n; i++){
			if (mask[i])
				re.push_back(s[i]);
		}
		return re;
	}

};

#if 0
class Solution316 {
public:
	string removeDuplicateLetters(string s) {
		int n = s.length();
		if (n <= 1)
			return s;
		vector<int> dup(26, -1);
		
		for (auto x : s){
			int index = x - 'a';
			if (dup[index] == -1){
				dup[index] = 0;
			}
			else if (dup[index] == 0){
				dup[index] = 1;
			}
		}

		vector<bool> mask(n, true);
		for (int i = 25; i >= 0; i--){
			if (dup[i] != 1)
				continue;
			dup[i] = 0;
			char now = 'a' + i;
			int loc = -1;
			for (int j = 0; j < n; j++){
				if (s[j] == now){
					loc = j;
					int next = j + 1;
					while (next < n && (dup[s[next] - 'a'] == 1 || mask[next]==false))
						next++;

					if (next >= s.length() || s[next] > now)
						break;
				}
				
			}

			for (int j = 0; j < n; j++){
				if (j != loc && s[j] == now)
					mask[j] = false;
			}

		}

		string re;
		for (int i = 0; i < n; i++){
			if (mask[i])
				re.push_back(s[i]);
		}

		return re;
	}
};
#endif