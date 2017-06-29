#include <vector>
#include <algorithm>

using namespace std;

class Solution152 {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int gmax = nums[0];
		int lmax = gmax, lmin = gmax;
		for (size_t i = 1; i < nums.size(); i++)
		{
			int temp = lmax;
			lmax = max(max(nums[i], lmax * nums[i]),lmin * nums[i]);
			lmin = min(min(nums[i], lmin * nums[i]), temp* nums[i]);
			gmax = max(gmax, lmax);
		}
		return gmax;
	}
};