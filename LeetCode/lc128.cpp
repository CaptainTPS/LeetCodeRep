//128. Longest Consecutive Sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> n;
        for (int i = 0; i < nums.size(); ++i)
        {
        	n.insert(nums[i]);
        }
        int cnt = 0;
        while(!n.empty()){
        	int h = *(n.begin());
        	int l = *(n.begin());
        	n.erase(h);
        	while(n.find(++h)!= n.end()){
        		n.erase(h);
        	}
        	while(n.find(--l) != n.end()){
        		n.erase(l);
        	}
        	if (h - l  - 1 > cnt)
        		cnt = h - l - 1; 
        }
        return cnt;
    }
};