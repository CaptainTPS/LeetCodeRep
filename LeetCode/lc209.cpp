#include <vector>
#include <algorithm>

using namespace std;

class Solution209 {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int sum = 0;
		int left = 0;
		int right = 0;
		int re = nums.size() + 1;
		for (int i = 0; i < nums.size(); i++)
		{
			right++;
			sum += nums[i];
			if (sum < s)
				continue;

			while (sum >= s){
				sum -= nums[left++];
			}
			sum += nums[--left];
			re = min(re, right - left);
		}
		if (re > nums.size())
			return 0;
		else
			return re;
	}
};