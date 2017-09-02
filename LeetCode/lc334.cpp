#include <vector>
using namespace std;

class Solution334 {
public:
	typedef long long ll;
	bool increasingTriplet(vector<int>& nums) {
		ll c1 = 1e11, c2 = 1e11;
		for (auto x : nums){
			if (x <= c1)
				c1 = x;
			else if (x <= c2)
				c2 = x;
			else
				return true;
		}
		return false;
	}
};