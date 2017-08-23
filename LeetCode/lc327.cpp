#include <vector>
#include <algorithm>

using namespace std;

class Solution327 {
public:
	typedef long long ll;
	ll mergeCount(vector<ll>& sum, ll left, ll right, ll lower, ll upper){
		if (left >= right)
			return 0;
		
		ll mid = (left + right) / 2;
		ll cnt = mergeCount(sum, left, mid, lower, upper) + mergeCount(sum, mid + 1, right, lower, upper);

		ll j = mid + 1;
		for (ll i = left; i <= mid; i++){
			while (j <= right && sum[j] - sum[i] < lower)
				j++;
			ll k = j;
			while (k <= right && sum[k] - sum[i] <= upper)
				k++;
			cnt += k - j;
		}
		
		inplace_merge(sum.begin() + left, sum.begin() + mid + 1, sum.begin() + right + 1);
		
		return cnt;
	}

	int countRangeSum(vector<int>& nums, int lower, int upper) {
		ll n = nums.size();
		
		vector<ll> prefix(n + 1, 0);
		for (ll i = 0; i < n; i++){
			prefix[i + 1] = prefix[i] + nums[i];
		}
		ll cnt = mergeCount(prefix, 0, n, lower, upper);
		return cnt;
	}
};