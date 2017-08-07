#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution220 {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		typedef long long ll;
		if (nums.empty())
			return false;
		if (k <= 0 || t < 0)
			return false;
		set<ll> window;
		for (int i = 0; i < nums.size(); i++)
		{
			ll x = nums[i];
			if (i > k)
				window.erase(nums[i - k - 1]);
			auto finder = window.lower_bound(x - t);
			if (finder != window.end() && *finder - x <= t)
				return true;
			window.insert(x);
		}
		return false;
	}
};

#if 0
//TLE
class Solution220 {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		typedef long long ll;
		if (nums.empty())
			return false;
		if(t <0 || k<=0)
			return false;
		
		for (int i = 0; i < nums.size(); i++)
		{
			ll x = nums[i];
			for (int j = i + 1; j < nums.size() && j <= i + k; j++)
			{
				ll y = nums[j];
				if (abs(x - y) <= t)
					return true;
			}
		}
		return false;
	}

};

#endif