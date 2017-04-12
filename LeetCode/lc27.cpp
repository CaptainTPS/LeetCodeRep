#include <cstdlib>
#include <vector>

using namespace std;


int removeElement(vector<int>& nums, int val) {
	if (nums.empty())
	{
		return 0;
	}
	int left = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] !=val)
		{
			nums[left++] = nums[i];
		}
	}
	return left;
}

int main27(){
	int data[7] = { 1, 2, 3, 2, 4, 3, 5 };
	vector<int> d(data, data + 7);
	int m = removeElement(d, 3);
	return 0;
}