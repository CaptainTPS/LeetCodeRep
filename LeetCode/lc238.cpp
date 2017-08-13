class Solution238 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n ==0)
        	return vector<int>();
        vector<int> front(n, 0);
        vector<int> tail(n, 0);
        front[0] = nums[0];
        for(int i = 1; i < n; i++){
        	front[i] = front[i-1] * nums[i];
        }
        tail[n-1]= nums[n-1];
        for(int i = n -2; i >=0; i--){
        	tail[i] = tail[i+1] * nums[i];
        }
        vector<int> result(n, 1);
        for(int i = 0; i< n; i++){
        	int f , t;
        	if(i >0)
        		f = front[i-1];
        	else
        		f = 1;
        	if(i <n-1)
        		t = tail[i + 1];
        	else
        		t = 1;
        	result[i] = f * t;
        }
        return result;
    }
};