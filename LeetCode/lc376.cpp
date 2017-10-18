//lc376
class Solution376 {
public:
    int wiggleMaxLength(vector<int>& nums) {
    	int n = nums.size();
    	if(n<=1)
    		return n;

        int ptr = 1;
        int cnt = 1;

        while(ptr < n){
        	while(ptr < n && nums[ptr] == nums[ptr-1]){
        		ptr++;
        		continue;
        	}
        	if(ptr >= n)
        		break;
        	if (nums[ptr] > nums[ptr-1]){
        		cnt++;
        		while(ptr < n && nums[ptr] >= nums[ptr-1])
        			ptr++;
        		continue;
        	}
        	if (nums[ptr] < nums[ptr-1]){
        		cnt++;
        		while(ptr < n && nums[ptr] <= nums[ptr-1])
        			ptr++;
        		continue;
        	}
        }
        return cnt;
    }
};