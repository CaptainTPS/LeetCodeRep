//384. Shuffle an Array

class Solution {
public:
    Solution(vector<int> nums) {
        data = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return data;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        auto copy = data;
        int n = copy.size();
        while(n > 1){
        	int c = rand() % n;
        	n--;
        	swap(copy[c], copy[n]);
        }
        return copy;
    }

private:
	vector<int> data;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */