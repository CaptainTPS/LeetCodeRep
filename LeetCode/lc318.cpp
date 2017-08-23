#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution318 {
public:
	bool compare(string& a, string& b){
		vector<int> f(26, 0);
		for (auto x : a)
			f[x - 'a']++;
		for (auto x : b){
			if (f[x - 'a'] != 0)
				return false;
		}
		return true;
	}

	int maxProduct(vector<string>& words) {
		int n = words.size();
		if (n <= 1)
			return 0;
		long long x = 0;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				if (compare(words[i], words[j])){
					x = max(x, (long long)(words[i].length() * words[j].length()));
				}
			}
		}
		return x;
	}
};