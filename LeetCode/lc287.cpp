#include <vector>

using namespace std;

class Solution287 {
public:
	typedef long long ll;

	int findDuplicate(vector<int>& nums) {
		ll n = nums.size();
		n--;
		if (n <= 0)
			return -1;

		int left = 1;
		int right = n;
		int cnt = 0;
		while (left < right){
			cnt = 0;
			int mid = (left + right) / 2;
			for (auto x : nums){
				if (x <= mid){
					cnt++;
				}
			}

			if (cnt > mid){
				right = mid;
			}
			else{
				left = mid + 1;
			}

		}
		return left;
	}
};