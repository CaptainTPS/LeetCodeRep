#include <vector>

using namespace std;

class Solution154 {
public:
	int findMin(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		while (left < right && nums[left] >= nums[right]){
			int mid = (left + right) / 2;
			if (nums[mid] > nums[left])
				left = mid + 1;
			else if (nums[mid] == nums[left])
				left++;
			else
				right = mid;
		}
		return nums[left];
	}
};