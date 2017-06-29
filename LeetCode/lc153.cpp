#include <vector>

using namespace std;

class Solution153 {
public:
	int findMin(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		while (left < right){
			int mid = (left + right) / 2;
			if (nums[mid] >= nums[left] && nums[mid] >= nums[right])
				left = mid + 1;
			else if (nums[mid] >= nums[left] && nums[mid] < nums[right])
				right = mid - 1;
			else
				right = mid;
		}
		return nums[left];
	}
};
