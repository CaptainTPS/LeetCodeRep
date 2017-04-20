#include <cstdlib>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

int biSearch(vector<int>& all, int target, int begin, int end){
	//return the last index <= target
	int left = begin;
	int right = end;
	while (left<=right)
	{
		int mid = (left + right) / 2;
		if (all[mid] == target)
		{
			return mid;
		}
		if (all[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	if (right < begin)
	{
		right = -1;
	}
	return right;
}

vector<vector<int>> result;
vector<int> temp;

void dfs(vector<int>& cand, int target, int begin, int end){
	if (target == 0)
	{
		result.push_back(temp);
	}
	int n = biSearch(cand, target, begin, end);
	if (n == -1)
	{
		return;
	}
	for (int i = begin; i <= n; i++)
	{
		temp.push_back(cand[i]);
		dfs(cand, target - cand[i], i, n);
		temp.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	dfs(candidates, target, 0, candidates.size() - 1);
	return result;
}

int main39(){

	return 0;
}