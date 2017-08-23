#include <vector>

using namespace std;

class Solution330 {
public:
	typedef long long ll;
	int minPatches(vector<int>& nums, int n) {
		int cnt = 0;
		ll maxnow = 0;
		int ptr = 0;
		while (maxnow < n){
			if (ptr >= nums.size() || nums[ptr] > maxnow + 1){
				cnt++;
				maxnow = maxnow * 2 + 1;
			}
			else
			{
				maxnow += nums[ptr];
				ptr++;
			}
		}
		return cnt;
	}
};