#include <vector>
#include <algorithm>

using namespace std;

class Solution213 {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n < 2){
			return n == 0? 0 : nums[0];
		}
		return max(myrob(nums, 0, n - 2), myrob(nums, 1, n - 1));
	}

	int myrob(vector<int>& nums, int left, int right){
		int prepre = 0; int pre = 0;
		for (int i = left; i <= right; i++)
		{
			int curr = max(prepre + nums[i], pre);
			prepre = pre;
			pre = curr;
		}
		return pre;
	}
};