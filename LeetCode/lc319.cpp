#include <vector>

using std::vector;

class Solution319 {
public:
	typedef long long ll;

	int bulbSwitch(int n) {
		int cnt = 0;
		for (ll i = 1; i*i <= n; i++)
			cnt++;
		return cnt;
	}
};