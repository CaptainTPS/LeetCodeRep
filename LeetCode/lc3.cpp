#include <cstdlib>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s) {
	unordered_set<char> now;
	unordered_set<char>::iterator finder;
	int cnt = 0;
	int temp = 0;
	for (int i = 0; i < s.length(); i++) {
		for (int j = i; j < s.length(); j++)
		{
			finder = now.find(s[j]);
			if (finder == now.end()) {
				now.insert(s[j]);
				temp++;
			}
			else {
				break;
			}
		}
		now.clear();
		if (temp > cnt)
			cnt = temp;
		temp = 0;
	}
	return cnt;
}

int main3() {
	string s;
	s ="abcabcbb";
	int m = lengthOfLongestSubstring(s);
	cout << m << endl;

	return 0;
}