#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<vector<int>> all;

void dfs(vector<int>& nums, int loc){
	if (loc == nums.size())
	{
		all.insert(nums);
		//result.push_back(nums);
		return;
	}

	for (int i = loc; i < nums.size(); i++)
	{
		if (i != loc && nums[i] == nums[i-1])
		{
			continue;
		}
		swap(nums[i], nums[loc]);
		dfs(nums, loc + 1);
		swap(nums[i], nums[loc]);
	}

}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	dfs(nums, 0);
	vector<vector<int>> re(all.begin(), all.end());
	return re;
}

int main47(){
	int data[3] = { 1, 1, 3 };
	vector<int> test(data, data + 3);
	vector<vector<int>> re = permuteUnique(test);
	return 0;
}