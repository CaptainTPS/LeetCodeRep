#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	if (nums.size() < 3)
	{
		return 0;
	}
	int min = abs(nums[0] + nums[1] + nums[2] - target);
	int sum = nums[0] + nums[1] + nums[2];

	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		int left = i + 1;
		int right = (int)nums.size() - 1;
		while (left < right)
		{
			int tsum = nums[i] + nums[left] + nums[right];
			if (tsum == target)
			{
				return tsum;
			}
			if (abs(tsum - target) < min)
			{
				min = abs(tsum - target);
				sum = tsum;
			}
			if(tsum - target < 0)
			{
				left++;
			}
			if (tsum - target > 0)
			{
				right--;
			}
		}
	}
	return sum;
}

int main(){
	int S[3] = { 0,1,2 };
	vector<int> t;
	for (int i = 0; i < 3; i++)
	{
		t.push_back(S[i]);
	}
	int re = threeSumClosest(t, 3);

	return 0;
}