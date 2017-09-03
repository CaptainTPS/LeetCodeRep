#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution347 {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		if (nums.empty())
			return vector<int>();

		unordered_map<int, int> itofre;
		for (auto x : nums){
			auto finder = itofre.find(x);
			if (finder == itofre.end())
				itofre.insert({ x, 1 });
			else
			{
				finder->second++;
			}
		}

		vector<vector<int>> cnt(nums.size() + 1);

		for (auto itr = itofre.begin(); itr != itofre.end(); itr++){
			cnt[itr->second].push_back(itr->first);
		}
		vector<int> result;
		for (int cnow = nums.size(); cnow >= 1; cnow--){
			if (!cnt[cnow].empty()){
				result.insert(result.end(), cnt[cnow].begin(), cnt[cnow].end());
			}
			if (result.size() >= k)
				break;
		}
		return result;
	}
};