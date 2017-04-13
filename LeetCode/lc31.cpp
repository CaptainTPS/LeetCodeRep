#include <cstdlib>
#include <vector>

using namespace std;

void nextPermutation(vector<int>& nums) {
	if (nums.size() < 2)
	{
		return;
	}
	int mostLeft = nums.size() - 1;
	while (nums[mostLeft - 1] >= nums[mostLeft])
	{
		mostLeft--;
		if (mostLeft == 0)
		{
			break;
		}
	}
	//change once
	if (mostLeft != 0)
	{
		int mark = mostLeft;
		while (nums[mark] > nums[mostLeft - 1])
		{
			mark++;
			if (mark == nums.size())
			{
				break;
			}
		}
		int temp = nums[mostLeft - 1];
		nums[mostLeft - 1] = nums[mark - 1];
		nums[mark - 1] = temp;
	}

	//resort
	int right = nums.size() - 1;
	int left = mostLeft;
	while (left < right)
	{
		int temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;

		left++;
		right--;
	}
}

int main31(){
	int data[6] = { 6, 5, 4, 3, 2 ,1};
	vector<int> d(data, data + 6);

	nextPermutation(d);
	nextPermutation(d);

	return 0;
}