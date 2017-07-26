#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution179 {
public:
	static bool cmp(int a, int b){
		string as = to_string(a) + to_string(b);
		string bs = to_string(b) + to_string(a);

		int ptr = 0;
		while (ptr < as.length() && ptr < bs.length()){
			if (as[ptr] > bs[ptr])
				return true;
			if (as[ptr] < bs[ptr])
				return false;
			ptr++;
		}
		
		return a<b;
	}

	string largestNumber(vector<int>& nums) {
		string re;
		if (nums.empty())
			return re;

		sort(nums.begin(), nums.end(), cmp);
		for (auto i : nums){
			if (re.empty() && i == 0)
				continue;
			re += to_string(i);
		}
		if (re.empty())
			re += '0';
		return re;
	}
};