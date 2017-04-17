#include <cstdlib>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
	int size = nums.size();
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[low] < nums[mid])
		{
			if (nums[low] <= target&&target < nums[mid])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		else if (nums[mid] < nums[high])
		{
			if (nums[mid] < target && target <= nums[high])
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
		else if (nums[low] == nums[mid])
		{
			low++;
		}
		else if (nums[high] == nums[mid])
		{
			high--;
		}
	}
	return -1;
}

int main33(){
	int data[7] = { 4, 5, 6, 7, 0, 1, 2 };
	vector<int> d(data, data + 7);
	int m = search(d, 4);
	return 0;
}