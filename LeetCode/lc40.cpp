#include <cstdlib>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
namespace lc40{
	struct hash_v
	{
		size_t operator()(vector<int> a) const
		{
			size_t t = hash<int>()(a[0]);
			for (int i = 1; i < a.size(); i++)
			{
				t = t^hash<int>()(a[i]);
			}
			return t;
		}
	};

	int biSearch(vector<int>& all, int target, int begin, int end){
		//return the last index <= target
		int left = begin;
		int right = end;
		while (left <= right)
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
	unordered_set<vector<int>, hash_v> tempResult;
	vector<int> temp;

	void dfs(vector<int>& cand, int target, int begin, int end){
		if (target == 0)
		{
			auto finder = tempResult.find(temp);
			if (finder == tempResult.end())
			{
				tempResult.insert(temp);
			}
		}
		int n = biSearch(cand, target, begin, end);
		if (n == -1)
		{
			return;
		}
		for (int i = begin; i <= n; i++)
		{
			temp.push_back(cand[i]);
			dfs(cand, target - cand[i], i + 1, n);
			temp.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		dfs(candidates, target, 0, candidates.size() - 1);
		for (auto i = tempResult.begin(); i != tempResult.end(); i++)
		{
			result.push_back(*i);
		}
		return result;
	}
}


int main40(){
	int data[7] = { 10, 1, 2, 7, 6, 1, 5 };
	vector<int> input(data, data + 7);
	int t = 8;
	vector<vector<int>> re = lc40::combinationSum2(input, t);
	return 0;
}