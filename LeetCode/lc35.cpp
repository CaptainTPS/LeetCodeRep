#include <cstdlib>
#include <vector>

using std::vector;

int searchInsert(vector<int>& nums, int target) {
	int low = 0;
	int high = nums.size() - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] < target)
		{
			low = mid + 1;
		}
		else if (nums[mid] > target)
		{
			high = mid - 1;
		}
	}
	return low;
}

int main35(){
	int data[4] = { 1, 3, 5, 6 };
	vector<int> t(data, data + 4);
	int re = searchInsert(t, 0);
	return 0;
}