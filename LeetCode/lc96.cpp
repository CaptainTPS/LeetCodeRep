#include <cstdlib>
#include <vector>

using namespace std;

class Solution96 {
public:
	vector<int> cnt;
	int numTrees(int n) {
		if (n == 0)
		{
			return 0;
		}

		cnt = vector<int>(n + 1, -1);
		cnt[0] = 1;
		cnt[1] = 1;

		for (size_t i = 2; i <= n; i++)
		{
			int c = 0;
			for (size_t j = 1; j <= i; j++)
			{
				c += cnt[j - 1] * cnt[i - j];
			}
			cnt[i] = c;
		}

		return cnt[n];
	}
};