//78 subsets
class Solution {
public:
	set<set<int>> all;
	void dfs(int n, std::vector<int>& nums, set<int>& s){
		if (n == nums.size())
		{
			all.insert(s);
			return;
		}

		s.insert(nums[n]);
		dfs(n+1,nums, s);
		s.erase(nums[n]);
		dfs(n+1,nums,s);

	}


    vector<vector<int>> subsets(vector<int>& nums) {
        set<int> s;
        dfs(0, nums, s);
        vector<vector<int>> a;
        for (auto i = all.begin(); i != all.end(); ++i)
        {
        	std::vector<int> temp = vector<int>(i->begin(), i->end());
        	a.push_back(temp);
        }
        return a;
    }
};