#include <vector>

using namespace std;

class Solution162 {
public:
	int findPeakElement(vector<int>& nums) {
		int s = nums.size();
		if (s <= 1)
			return 0;
		int left = 0, right = s - 1;
		while (left < right - 1){
			int mid = (left + right) / 2;
			if (nums[mid - 1]< nums[mid] && nums[mid] > nums[mid + 1]){
				return mid;
			}
			else if (nums[mid - 1] < nums[mid]){
				left = mid + 1;
			}
			else{
				right = mid - 1;
			}
		}
		return nums[left] > nums[right] ? left : right;
	}
};