class Solution229 {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        if(nums.size()<=2){
        	if(nums.size()>=1)
        		result.push_back(nums[0]);
        	if(nums.size() == 2 && nums[0] != nums[1])
        		result.push_back(nums[1]);
        	return result;
        }

        int n1= 0, n2 = 1;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i<nums.size();i++){
        	int x = nums[i];
        	if(x == n1)
        		cnt1++;
        	else if(x == n2)
        		cnt2++;
        	else if(cnt1 == 0){
        		n1 = x;
        		cnt1++;
        	}else if(cnt2 == 0){
        		n2 = x;
        		cnt2++;
        	}else{
        		cnt1--;
        		cnt2--;
        	}

        }
        cnt2 = cnt1 = 0;
        for(auto x : nums){
        	if(x == n1)
        		cnt1++;
        	if(x == n2)
        		cnt2++;
        }
        if(cnt1 > nums.size() / 3)
        	result.push_back(n1);
        if(cnt2 > nums.size() / 3)
        	result.push_back(n2);
        return result;
    }
};