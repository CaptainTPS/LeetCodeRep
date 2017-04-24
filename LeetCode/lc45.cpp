#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int jump(vector<int>& nums) {
	int *dp = new int[nums.size()];
	fill(dp, dp + nums.size(), 0);
	bool flag = false;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = nums[i]; j >=1; j--)
		{
			if (i + j > nums.size() - 1)
			{
				continue;
			}
			if (i + j == nums.size() - 1)
			{
				flag = true;
			}
			int step = dp[i] + 1;
			if (dp[i + j] == 0)
			{
				dp[i + j] = step;
			}
			else
			{
				break;
			}
			if (flag)
			{
				break;
			}
		}
		if (flag)
		{
			break;
		}
	}
	int re = dp[nums.size() - 1];
	delete[] dp;
	return re;
}


int main45(){
	int data[5] = { 2, 3, 1, 1, 4 };
	vector<int> test(data, data + 5);
	int re = jump(test);
	return 0;
}
