class Solution228 {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.empty())
        	return result;
        int start = nums[0];
        int pre = start;
        for(int i = 1; i<= nums.size(); i++){
        	if(i < nums.size() && nums[i] <= pre + 1){
        		pre = nums[i];
        	}else{
        		string t = "";
        		t += to_string(start);
        		if(pre != start){
        			t +="->";
        			t += to_string(pre);
        		}
        		result.push_back(t);
        		if(i < nums.size())
        			start = pre = nums[i];
        	}

        }
        return result;
    }
};