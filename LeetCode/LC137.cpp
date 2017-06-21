#include <vector>

using namespace std;

class Solution137 {
public:
	int singleNumber(vector<int>& nums) {
		vector<int> bit(32, 0);
		for (auto n : nums){
			for (size_t i = 0; i < 32; i++)
			{
				bit[i] += ((n & (1 << i)) == 0 ? 0 : 1);
			}
		}
		int re = 0;
		for (size_t i = 0; i < 32; i++)
		{
			re |= ((bit[i]%3) << i);
		}
		return re;
	}
};
