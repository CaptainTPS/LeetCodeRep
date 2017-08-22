#include <vector>
#include <algorithm>

using namespace std;

class Solution313 {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> nums;
		nums.push_back(1);
		if (n == 1)
			return 1;
		vector<int> ptr(primes.size(), 0);
		while (nums.size() < n){
			int minnow = 1e10;
			for (int i = 0; i < primes.size(); i++){
				int before = nums[ptr[i]];
				minnow = min(minnow, primes[i] * before);
			}
			nums.push_back(minnow);
			for (int i = 0; i < primes.size(); i++){
				if (minnow == nums[ptr[i]] * primes[i])
					ptr[i]++;
			}
		}
		return nums.back();
	}
};