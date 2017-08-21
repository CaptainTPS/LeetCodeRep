#include <vector>
#include <algorithm>

using namespace std;

class Solution309 {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n <= 1)
			return 0;
		vector<int> s0(n);
		vector<int> s1(n);
		vector<int> s2(n);
		s0[0] = 0;
		s1[0] = -prices[0];
		s2[0] = -1e9;
		
		for (int i = 1; i < n; i++)
		{
			s0[i] = max(s0[i - 1], s2[i - 1]);
			s1[i] = max(s0[i - 1] - prices[i], s1[i - 1]);
			s2[i] = s1[i - 1] + prices[i];
		}

		return max( max(s0.back(), s1.back()), s2.back());
	}
};