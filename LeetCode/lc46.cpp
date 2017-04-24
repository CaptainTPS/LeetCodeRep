#include <cstdlib>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

unordered_set<int> occupied;
vector<vector<int>> allre;

void dfs(vector<int>& nums, vector<int>& temp){
	if (temp.size() == nums.size())
	{
		allre.push_back(temp);
		return;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		int t = nums[i];
		auto finder = occupied.find(t);
		if (finder != occupied.end())
		{
			continue;
		}
		occupied.insert(t);
		temp.push_back(t);
		dfs(nums, temp);
		temp.pop_back();
		occupied.erase(t);
	}

}

vector<vector<int>> permute(vector<int>& nums) {
	vector<int> temp;
	dfs(nums, temp);
	return allre;
}

int main46(){
	int data[3] = { 1, 2, 3 };
	vector<int> test(data, data + 3);
	vector<vector<int>> re = permute(test);
	return 0;
}