#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution90 {
public:
	struct cmp
	{
		bool operator()(vector<int> a, vector<int> b){
			for (size_t i = 0; i < a.size(); i++)
			{
				if (b.size() == i)
				{
					return false;
				}
				if (a[i] > b[i])
				{
					return true;
				}
				else if (a[i] < b[i])
				{
					return false;
				}
			}
			return true;
		}
	};

	set<vector<int>> all;


	void dfs(vector<int>& nums, vector<int>& temp, int now){
		if (now == nums.size())
		{
			vector<int> store(temp);
			sort(store.begin(), store.end());
			all.insert(store);
			return;
		}
		temp.push_back(nums[now]);
		dfs(nums, temp, now + 1);
		temp.pop_back();
		dfs(nums, temp, now + 1);
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<int> ttt;
		dfs(nums, ttt, 0);
		vector<vector<int>> result;
		for (auto i = all.begin(); i != all.end(); i++)
		{
			vector<int> temp(i->begin(), i->end());
			result.push_back(temp);
		}
		return result;
	}
};

int main90(){
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(1);

	Solution90 ss;
	ss.subsetsWithDup(nums);
	return 0;
}