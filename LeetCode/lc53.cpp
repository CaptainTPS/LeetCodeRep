#include <cstdlib>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
	int maxsum = nums[0];
	int tempsum = maxsum;
	for (int i = 1; i < nums.size(); i++)
	{
		if (tempsum >=0)
		{
			tempsum += nums[i];
		}
		else
		{
			tempsum = nums[i];
		}
		
		if (tempsum > maxsum)
		{
			maxsum = tempsum;
		}
	}
	return maxsum;
}

int main53(){
	int data[9] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	vector<int> t(data, data + 9);
	int re = maxSubArray(t);
	return 0;
}