class Solution239 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> maxpos;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i)
        {
        	if(!maxpos.empty() && maxpos.front() == i - k)
        		maxpos.pop_front();
        	while(!maxpos.empty() && nums[ maxpos.back()] < nums[i])
        		maxpos.pop_back();
        	maxpos.push_back(i);
        	if(i >=k - 1){
        		result.push_back(nums[maxpos.front()]);
        	}
        }
        return result;
    }
};