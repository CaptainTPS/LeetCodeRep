#include <cstdlib>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	if (nums.empty())
	{
		return 0;
	}
	int left = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] != nums[left])
		{
			nums[++left] = nums[i];
		}
	}
	return left + 1;
}

int main26(){
	int data[5] = { 1, 2, 2, 2, 3 };
	vector<int> all(data, data+5);
	int m = removeDuplicates(all);
	return 0;
}