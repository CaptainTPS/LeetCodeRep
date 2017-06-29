#include <string>

using namespace std;

class Solution151 {
public:
	void reverseWords(string &s) {
		if (s.empty())
			return;
		while (s.back() == ' ')
			s.pop_back();
		int start, end = -2;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' '){
				start = i;
				while (i < s.length() && s[i] != ' ')
					i++;
				i--;
				end = i;
				rev(s, start, end);
			}
			else
			{
				while (i + 1 < s.length() && s[i + 1] == ' ')
					s.erase(s.begin() + i);
			}
		}
		rev(s, 0, s.length() - 1);
		while (s.back() == ' ')
			s.pop_back();
	}
private:
	void rev(string &s, int left, int right){
		while (left < right){
			char c = s[left];
			s[left] = s[right];
			s[right] = c;
			++left;
			--right;
		}
	}
};