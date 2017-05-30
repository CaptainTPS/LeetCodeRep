//80. Remove Duplicates from Sorted Array II
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <=2)
        {
        	return nums.size();
        }
        int ptr1=1, ptr2=1;
        int times = 1;
        int now = nums[0];
        while(ptr2 != nums.size()){
        	if (nums[ptr2]==now)
        	{
        		if (times < 2)
        		{
        			times++;
        			nums[ptr1] = nums[ptr2];
        			ptr1++;
        			ptr2++;
        		}else{
        			ptr2++;
        		}
        	}else{
        		now = nums[ptr2];
        		nums[ptr1] = nums[ptr2];
        		times = 1;
        		ptr1++;
        		ptr2++;
        	}
        }
        return ptr1;
    }
};