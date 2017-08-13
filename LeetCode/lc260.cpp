class Solution260 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int r1 = 0;
        for(auto x : nums)
            r1 ^= x;
        int index = 1;
        while((r1 & index) == 0){
            index <<=1;
        }
        int r2 = 0, r3 = 0;
        for(auto x : nums){
            if(x & index)
                r2 ^= x;
            else
                r3 ^= x;
        }
        vector<int> re = {r2,r3};
        return re;
    }
};