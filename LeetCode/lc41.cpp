#include <cstdlib>
#include <vector>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
	int temp;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] <= 0)
		{
			continue;
		}
		if (nums[i] >= nums.size())
		{
			continue;
		}
		if (nums[i] == i+1)
		{
			continue;
		}
		if (nums[nums[i] - 1] == nums[i])
		{
			continue;
		}
		temp = nums[nums[i]-1];
		nums[nums[i] - 1] = nums[i];
		nums[i] = temp;
		i--;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != i + 1)
		{
			return i + 1;
		}
	}
	return nums.size()+1;
}

int main41(){
	
	return 0;
}