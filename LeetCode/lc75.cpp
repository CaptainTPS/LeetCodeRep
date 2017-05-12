#include <cstdlib>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
	int cnt[3] = {0,0,0};
	for (int i = 0; i < nums.size(); i++)
	{
		cnt[nums[i]]++;
	}
	if (cnt[0] !=0)
		fill(nums.begin(), nums.begin() + cnt[0], 0);
	if (cnt[1] != 0)
		fill(nums.begin() + cnt[0], nums.begin() +cnt[0] + cnt[1], 1);
	if (cnt[2] != 0)
		fill(nums.begin() + cnt[0] + cnt[1], nums.begin() + cnt[0] + cnt[1] + cnt[2], 2);
}

int main75(){
	vector<int> test;
	test.push_back(1);
	test.push_back(0);
	test.push_back(0);
	sortColors(test);
	return 0;
}