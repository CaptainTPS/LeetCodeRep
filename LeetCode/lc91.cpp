#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution91 {
public:
	int numDecodings(string s) {
		if (s.empty())
		{
			return 0;
		}
		vector<int> cnt(s.length() + 1, 0);
		cnt[0] = 1;
		for (size_t i = 1; i <= s.length(); i++)
		{
			if (s[i-1] != '0')
			{
				cnt[i] += cnt[i - 1];
			}
			if (i >=2)
			{
				int t = s[i - 2] - '0';
				t = t * 10 + (s[i - 1] - '0');
				if (t >= 10 && t <= 26)
				{
					cnt[i] += cnt[i - 2];
				}
			}
		}

		return cnt[s.length()];

	}
};